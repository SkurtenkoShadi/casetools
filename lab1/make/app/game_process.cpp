#include "game_process.h"

void game_process(sf::RenderWindow &window, Cursors &cursor){

    /*инициализация объектов игрового процесса,окон и датчиков*/
    GameObject object;
    MenuBar upperParametr;
    ToolBar lowerParametr;
    GameEndWindow endWindow;

    /*инициализация флагов состояния игры*/
    bool gameRun=true;
    bool gameOver=false;
    bool gamePaused=false;

    sf::Clock globalTime;
    sf::Clock gameTime;
    float runeUPDATEtime=0;

    std::minstd_rand simple_rand;

    window.setKeyRepeatEnabled(false);

    /*главный цикл игрового процесса*/
    while(gameRun && !gameOver){

        /*Получаем время для анимации объектов.*/
        /*Снимаем часть нагрузки с процессора.*/
        float time = (float)gameTime.getElapsedTime().asMicroseconds();
        gameTime.restart();
        time = time / 800;

        /*обновляем игровой таймер*/
        lowerParametr.get_time(globalTime,simple_rand);

        /*если прошло 10 минут,то начинается следующий раунд*/
        upperParametr.check_for_next_round(globalTime,lowerParametr.addToTimer,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage);

        /*обрабатываем нажатие клавиши выстрела*/
        hero_shot(object,upperParametr,lowerParametr,time,window);

        /*двигаем главного героя ,если были нажати клавиши управления*/
        move_hero(object,time,-1);

        /*обрабатываем нанесения урона противниками*/
        enemy_hit(object,lowerParametr,time);

        /*обработка движений противников по карте*/
        move_enemy(object,time,simple_rand);

        /*проверяем:где была нажата левая кнопка мыши*/
        gamePaused=mouse_click(upperParametr,cursor,window);

        if(gamePaused)
            /*получаем знак о нажатой кнопке в меню "Пауза"*/
            gameRun=pause_menu(window,upperParametr,lowerParametr,cursor,object,globalTime,gameTime);

        /*если на карте есть заспавненная руна, то обрабатываем её взаимодействие с героем*/
        if(lowerParametr.typeRandomedRune!=-1)
            take_rune(object,lowerParametr,upperParametr);

        /*производим анимацию руны или её появление на карте*/
        update_spawn_rune(object,lowerParametr,runeUPDATEtime,time,simple_rand);

        /*проверяем: разрушена ли база(здоровье равно 0)*/
        gameOver=end_game(object,endWindow);

        /*отрисовываем элементы в окне*/
        game_draw(window,upperParametr,lowerParametr,object);
        window.draw(cursor.cursore);
        window.display();

        if(gameOver){
            /*отрисовываем эффект взрыва*/
            base_hero_explosion(window,upperParametr,lowerParametr,cursor,object,gameTime);
            /*вывод окна "Завершение игры"*/
            game_end_window(window,endWindow,upperParametr,lowerParametr,cursor,object,globalTime);
        }
    }
}
