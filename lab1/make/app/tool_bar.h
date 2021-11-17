#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include<SFML/Graphics.hpp>
#include<random>

/**
 * @ingroup objectClasses
 * @brief Праметры счётчиков,выводимых в нижней полоске игровогоокна
 */
class ToolBar{

    public:

        /*полоска toolbar внизу экрана*/
        sf::Sprite toolbarline;

        /*таймер*/
        sf::Text timer;
        sf::Sprite iconClock;
        int addToTimer;

        /*здоровье танка*/
        sf::Sprite hp_hero_red;
        sf::Sprite hp_hero_green;
        sf::Text textHHP;
        sf::Sprite iconHPhero;
        sf::Text valueHHPof;

        /*здоровье базы*/
        sf::Sprite hp_base_red_orange;
        sf::Sprite hp_base_green;
        sf::Text textBHP;
        sf::Sprite iconHPbase;
        sf::Text valueBHPof;

        /*здоровье противника*/
        sf::Sprite hp_enemy_red;
        sf::Sprite hp_enemy_green;
        sf::Text textEHP;
        sf::Sprite iconHPenemy;
        sf::Sprite iconEnemy;
        sf::Text valueEHPof;
        sf::Sprite iconDeadEnemy;
        bool drawIconDeadEnemy;

        /*таймер спавна случайной руны в случайном месте*/
        sf::Sprite iconTimer;
        sf::Text spawnTimer;
        int secondsUntilSpawn;
        int bufferSeconds;
        int typeRandomedRune;
        bool randomizeCoordinates;

        /*получить строку с текущим временем игры: hh:mm:ss*/
        void get_time(sf::Clock &clock,std::minstd_rand &simple_rand){

            int seconds=0;
            int minutes=0;
            int hours=0;

            const int lenght=12;
            char str[lenght]="";

            time=clock.getElapsedTime();
            seconds = time.asSeconds();

            /*получаем временные промежутки*/
            seconds+=addToTimer;
            minutes=((seconds / 60)%60);
            hours=seconds / 3600;
            seconds=seconds % 60;

            /*формируем строку таймера*/
            snprintf(str,lenght,"%d:%d:%d",hours,minutes,seconds);
            timer.setString(str);

            /*Контролируем таймер,отвечающий за спавн новой руны.*/
            /*После 60 секунд формируем координаты и тип новой руны.*/
            if((bufferSeconds<seconds)||(bufferSeconds==59&&seconds==0)){
                    bufferSeconds=seconds;
                if(secondsUntilSpawn==1){
                    secondsUntilSpawn=60;
                    randomizeRune(simple_rand);
                }else{
                    secondsUntilSpawn--;
                }
                update_spawnTimer();
            }

        }

        /*случайныйм образом определяем руну, которую будем спавнить и ставим флаг для вызова функции-выбора случайных координат расположения*/
        void randomizeRune(std::minstd_rand &simple_rand){

            typeRandomedRune=(simple_rand() % 4);
            randomizeCoordinates=true;

        }

        /*получаем время,с которого должен пойти отсчёт при возвражении в игру после паузы*/
        void add_to_time(sf::Clock &clock){

            time=clock.getElapsedTime();
            addToTimer+=time.asSeconds();

        }

        /*функция перезагрузки времени*/
        void reset_clock(sf::Clock &clock){

            clock.restart();

        }

        /*обработка взаимодействия между объектами: нанесение урона ,восстановление здоровья*/
        bool change_hero_base_hp(std::string object,std::string str,int value,int &objecthealth){

            const int lenght=4;
            char strHP[lenght]="";

            /*Определяем тип взаимодействия.*/
            /*Определяем количество зодоровья после взаимодействия.*/
            if(str=="healing"){
                objecthealth+=value;
                if(objecthealth>100 && object=="hero"){
                    objecthealth=100;
                } else if(objecthealth>200 && object=="base"){
                    objecthealth=200;
                }
            }else if(str=="damaging"){
                objecthealth-=value;
                if(objecthealth<0)
                  objecthealth=0;
            }else{
                return false;
            }

            /*формируем новое состояние здоровья для вывода на экран*/
            if(object=="hero"){
                hp_hero_green.setTextureRect(sf::IntRect(0,0,objecthealth*2,shapeHPF.getSize().y));
                snprintf(strHP,lenght,"%d",objecthealth);
                valueHHPof.setString(strHP);
            }else if(object=="base"){
                hp_base_green.setTextureRect(sf::IntRect(0,0,objecthealth,shapeHPB.getSize().y));
                snprintf(strHP,lenght,"%d",objecthealth);
                valueBHPof.setString(strHP);
            }else{
                return false;
            }

            return true;

        }

        /*обновить полоску здоровья противника, выводимого в тулбаре*/
        void change_enemy_hp_line(int health,int MaxHealth,int enemyType){

            switch (enemyType) {
                case 0:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_butch.png"); break;}
                case 1:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_bat.png"); break;}
                case 2:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_heap.png"); break;}
                case 3:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_bull.png"); break;}
                case 4:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_mud_drop.png"); break;}
                case 5:{shapeIE.loadFromFile("../external/Sprites/icon_enemy_mushroom.png"); break;}
            }

            iconEnemy.setTexture(shapeIE);

            if(health==0){
                iconDE.loadFromFile("../external/Sprites/icon_enemy_dead.png");
                iconDE.createMaskFromColor(sf::Color::White);
                shapeIDE.loadFromImage(iconDE);
                iconDeadEnemy.setTexture(shapeIDE);
                drawIconDeadEnemy=true;
            }else{
                drawIconDeadEnemy=false;
            }

            const int lenght=4;
            char strHP[lenght]="";

            hp_enemy_green.setTextureRect(sf::IntRect(0,0,((health*200)/MaxHealth),shapeHPB.getSize().y));
            snprintf(strHP,lenght,"%d",health);
            valueEHPof.setString(strHP);

        }

        /*обновляем счётчик, отвечающий за количество секунд до следующего спавна руны*/
        void update_spawnTimer(){

           const int lenght=7;
           char seconds[lenght]="";
           snprintf(seconds,lenght,"%d sec",secondsUntilSpawn);
           spawnTimer.setString(seconds);

        }

    ToolBar(){

        /*инициализация добавочного значения к таймеру игры*/
        addToTimer=0;

        /*загружаем текст шрифта*/
        font.loadFromFile("../external/Text/Roboto-Italic.ttf");

        /*загружаем полоску tool bar*/
        shapeTBL.loadFromFile("../external/Sprites/line.png");
        toolbarline.setTexture(shapeTBL);
        toolbarline.setPosition(0,685);

        /*загружаем иконку часов для таймера*/
        shape.loadFromFile("../external/Sprites/iconTime.png");
        shape.createMaskFromColor(sf::Color(255,255,255));
        shapeIC.loadFromImage(shape);
        iconClock.setTexture(shapeIC);
        iconClock.setPosition(5,692);

        /*опредеояем шрифт,цыет и расположение таймера*/
        timer.setFont(font);
        timer.setPosition(50,693);
        timer.setFillColor(sf::Color(0,0,0));

        /*загружаем полоску здоровья танка , соответствующий текст "Здоровье Героя" , а также иконку*/
        shapeHPF.loadFromFile("../external/Sprites/hp_foreground.png");
        hp_hero_green.setTexture(shapeHPF);
        hp_hero_green.setPosition(300,720);

        shapeHPB.loadFromFile("../external/Sprites/hp_background.png");
        hp_hero_red.setTexture(shapeHPB);
        hp_hero_red.setPosition(300,720);

        textHHP.setFont(font);
        textHHP.setString("Hero HP");
        textHHP.setFillColor(sf::Color::Black);
        textHHP.setCharacterSize(20);
        textHHP.setPosition(300,695);

        iconH.loadFromFile("../external/Sprites/icon_hp_hero.png");
        iconH.createMaskFromColor(sf::Color::White);
        shapeIHPH.loadFromImage(iconH);
        iconHPhero.setTexture(shapeIHPH);
        iconHPhero.setPosition(480,695);

        valueHHPof.setFont(font);
        valueHHPof.setString("100");
        valueHHPof.setFillColor(sf::Color::Black);
        valueHHPof.setCharacterSize(20);
        valueHHPof.setPosition(440,695);

        /*загружаем полоску здоровья базы , соответствующий текст "Здоровье базы",а также иконку*/
        shapeHPF.loadFromFile("../external/Sprites/hp_foreground.png");
        hp_base_green.setTexture(shapeHPF);
        hp_base_green.setPosition(520,720);

        shapeHPAB.loadFromFile("../external/Sprites/hp_additnly_background.png");
        hp_base_red_orange.setTexture(shapeHPAB);
        hp_base_red_orange.setPosition(520,720);

        textBHP.setFont(font);
        textBHP.setString("Base HP");
        textBHP.setFillColor(sf::Color::Black);
        textBHP.setCharacterSize(20);
        textBHP.setPosition(520,695);

        iconB.loadFromFile("../external/Sprites/icon_hp_base.png");
        iconB.createMaskFromColor(sf::Color::White);
        shapeIHPB.loadFromImage(iconB);
        iconHPbase.setTexture(shapeIHPB);
        iconHPbase.setPosition(700,695);

        valueBHPof.setFont(font);
        valueBHPof.setString("200");
        valueBHPof.setFillColor(sf::Color::Black);
        valueBHPof.setCharacterSize(20);
        valueBHPof.setPosition(660,695);


        /*загружаем полоску здоровья противника , соответствующий текст "Здоровье противника",а также иконку*/
        shapeIE.loadFromFile("../external/Sprites/unknown_enemy.png");
        iconEnemy.setTexture(shapeIE);
        iconEnemy.setPosition(770,692);
        iconDeadEnemy.setPosition(770,692);
        drawIconDeadEnemy=false;

        shapeHPF.loadFromFile("../external/Sprites/hp_foreground.png");
        hp_enemy_green.setTexture(shapeHPF);
        hp_enemy_green.setPosition(820,720);

        shapeHPB.loadFromFile("../external/Sprites/hp_background.png");
        hp_enemy_red.setTexture(shapeHPB);
        hp_enemy_red.setPosition(820,720);

        textEHP.setFont(font);
        textEHP.setString("Enemy HP");
        textEHP.setFillColor(sf::Color::Black);
        textEHP.setCharacterSize(20);
        textEHP.setPosition(820,695);

        iconE.loadFromFile("../external/Sprites/icon_hp_enemy.png");
        iconE.createMaskFromColor(sf::Color::White);
        shapeIHPE.loadFromImage(iconE);
        iconHPenemy.setTexture(shapeIHPE);
        iconHPenemy.setPosition(995,695);

        valueEHPof.setFont(font);
        valueEHPof.setString("0");
        valueEHPof.setFillColor(sf::Color::Black);
        valueEHPof.setCharacterSize(20);
        valueEHPof.setPosition(940,695);

        /*загружаем иконку случайной руны и указываем позиции таймера на понеле тул бара*/
        iconRR.loadFromFile("../external/Sprites/iconRandomRune.png");
        iconRR.createMaskFromColor(sf::Color::White);
        shapeRR.loadFromImage(iconRR);
        iconTimer.setTexture(shapeRR);
        iconTimer.setPosition(1050,692);

        spawnTimer.setFont(font);
        spawnTimer.setFillColor(sf::Color::Black);
        spawnTimer.setPosition(1095,692);

        /*инициализация параметров для работы тамера спавна рун*/
        secondsUntilSpawn=60;
        bufferSeconds=0;
        typeRandomedRune=-1;
        randomizeCoordinates=false;
        update_spawnTimer();

    }

    private:

        sf::Font font;

        sf::Time time;

        sf::Texture shapeHPB;
        sf::Texture shapeHPAB;
        sf::Texture shapeHPF;

        sf::Image iconB;
        sf::Texture shapeIHPB;
        sf::Image iconH;
        sf::Texture shapeIHPH;
        sf::Image iconE;
        sf::Texture shapeIHPE;
        sf::Texture shapeIE;
        sf::Image iconDE;
        sf::Texture shapeIDE;

        sf::Image shape;
        sf::Texture shapeIC;

        sf::Image iconRR;
        sf::Texture shapeRR;

        sf::Texture shapeTBL;
};

#endif // TOOL_BAR_H
