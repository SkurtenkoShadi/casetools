#ifndef MENU_BAR_H
#define MENU_BAR_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

/**
 * @ingroup objectClasses
 * @brief Паметры счётчиков,выводимых в верхней полоске игрового окна
 */
class MenuBar{

    public:

        /*полоска меню-бара*/
        sf::Sprite menubarline;

        /*кнопка паузы*/
        sf::Sprite pauseButton;
        sf::Sprite pauseButtonText;
        int w;
        int h;

        /*окно паузы с кнопками*/
        sf::Sprite PauseMenu;

        sf::Sprite PauseMenuButtonExit;
        sf::Text ExitText;

        sf::Sprite PauseMenuButtonContinue;
        sf::Text ContinueText;

        /*текст с номером текущего раунда*/
        sf::Text roundText;

        /*счётчик подобранных рун-монеток*/
        sf::Sprite iconCounterCoins;
        sf::Text textCounterCoins;

        /*счётчик подобранных рун,увеличивающих урон героя*/
        /*счётчик показывает количество добавачного урона героя*/
        sf::Sprite iconCounterAddedDamage;
        sf::Text textCounterAddedDamage;
        int counterAddedDamage;
        /*базовый урон героя*/
        sf::Text basis_damage;


        /*увеличиваем счётчик подобранных рун типа "coin"*/
        void incr_counter_coins(int value){

            const int lenght=5;
            char strCoins[lenght]="";

            counterCoins+=value;
            snprintf(strCoins,lenght,"%d",counterCoins);
            textCounterCoins.setString(strCoins);

        }

        /*увеличиваем счётчик добавоччного урона героя при взятии руны типа "plus damahe"*/
        void incr_counter_added_damage(int value){

            const int lenght=6;
            char strAddedDamage[lenght]="";

            counterAddedDamage+=value;
            snprintf(strAddedDamage,lenght,"+%d",counterAddedDamage);
            textCounterAddedDamage.setString(strAddedDamage);

        }

        /*проверка на прошествие 10 минут*/
        void check_for_next_round(sf::Clock &clock,int addToTimer,int &addedDmgInPerct,int &addedHpInPerct){

            int time;
            int minutes;

            time=clock.getElapsedTime().asSeconds();
            minutes=(((time+addToTimer) / 60)%60);

            if(((minutes%10==0)&&(minutes==bufferTime))||((bufferTime==60)&&(minutes==0))){

                change_round();
                addedDmgInPerct+=5;
                addedHpInPerct+=5;

                if(bufferTime==60){
                    bufferTime=10;
                }else{
                    bufferTime+=10;
                }

            }

        }

        /*увеличиваем счётчик раунда после прошествия 10 минут*/
        void change_round(){

            const int lenght =10;
            char strRound[lenght]="";

            round++;

            snprintf(strRound,lenght,"Round %d",round);
            roundText.setString(strRound);

        }

    MenuBar(){

        /*загружаем текст шрифта*/
        font.loadFromFile("../external/Text/Roboto-Italic.ttf");

        /*инициализируем иекси "первый раунд"*/
        round = 0;
        roundText.setFont(font);
        roundText.setFillColor(sf::Color::Black);
        roundText.setPosition(520,7);
        change_round();

        /*загружаем полоску меню бара*/
        shapeMBL.loadFromFile("../external/Sprites/line.png");
        menubarline.setTexture(shapeMBL);

        /*загружаем кнопку меню бара*/
        shapePB.loadFromFile("../external/Sprites/pauseButton.png");
        pauseButton.setTexture(shapePB);
        pauseButton.setPosition(7,7);
        w=40;
        h=40;

        /*загружаем содержимое кнопки*/
        pausePict.loadFromFile("../external/Sprites/pauseButtonText.png");
        pausePict.createMaskFromColor(sf::Color(0,0,0));
        shapePBT.loadFromImage(pausePict);
        pauseButtonText.setTexture(shapePBT);
        pauseButtonText.setPosition(7,7);

        /*загржаем фон меню-паузы*/
        PM.loadFromFile("../external/Sprites/pauseMenu.png");
        PauseMenu.setTexture(PM);
        PauseMenu.setPosition(0,56);

        /*загружаем кнопку меню-паузы:Продолжить игру*/
        PMBC.loadFromFile("../external/Sprites/menuButton.png");
        PauseMenuButtonContinue.setTexture(PMBC);
        PauseMenuButtonContinue.setPosition(20, 96);

        /*загружаем текст кнопки*/
        ContinueText.setFont(font);
        ContinueText.setString("Continue game");
        ContinueText.setPosition(50,106);

        /*загружаем кнопку меню-паузы:Выход в главное меню*/
        PMBE.loadFromFile("../external/Sprites/menuButton.png");
        PauseMenuButtonExit.setTexture(PMBE);
        PauseMenuButtonExit.setPosition(20, 166);

        /*загружаем текст кнопки*/
        ExitText.setFont(font);
        ExitText.setString("Exit in main menu");
        ExitText.setPosition(35,170);

        /*инициализация счётчика добавочного урона*/
        shapeAddedDamage.loadFromFile("../external/Sprites/iconAddedDamage.png");
        iconCounterAddedDamage.setTexture(shapeAddedDamage);
        iconCounterAddedDamage.setPosition(880,7);

        counterAddedDamage=0;

        textCounterAddedDamage.setFont(font);
        textCounterAddedDamage.setFillColor(sf::Color(5,171,5));
        textCounterAddedDamage.setPosition(950,7);
        incr_counter_added_damage(0);

        /*выводим базовый урон героя*/
        basis_damage.setFont(font);
        basis_damage.setString("5");
        basis_damage.setFillColor(sf::Color::Black);
        basis_damage.setPosition(930,7);

        /*инициализация счётчика собранных монет*/
        shapeCoin.loadFromFile("../external/Sprites/iconCoin.png");
        iconCounterCoins.setTexture(shapeCoin);
        iconCounterCoins.setPosition(1050,7);

        counterCoins=0;

        textCounterCoins.setFont(font);
        textCounterCoins.setFillColor(sf::Color::Black);
        textCounterCoins.setPosition(1100,7);
        incr_counter_coins(0);

        /*минута для смены раунда*/
        bufferTime=10;

    }

    private:

        int round;
        int counterCoins;


        int bufferTime;

        sf::Font font;

        sf::Texture shapePB;
        sf::Texture shapeMBL;

        sf::Texture PM;
        sf::Texture PMBE;
        sf::Texture PMBC;

        sf::Image pausePict;
        sf::Texture shapePBT;

        sf::Texture shapeAddedDamage;

        sf::Texture shapeCoin;

};

#endif // MENU_BAR_H
