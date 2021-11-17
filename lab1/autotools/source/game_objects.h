#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include <vector>
#include<random>

/**
 * @ingroup objectClasses
 * @brief Параметры игровых объектов
 *
 * @see Hero, Runes, Enemys, Base
 */
class GameObject{
    public:

        class Map{

            public:

                /*параметры карты*/
                sf::Sprite sprite;
                float w;
                float h;

            Map(){

                /*загружаем игровую карту*/
                shapeBF.loadFromFile("../external/Sprites/battle_field.png");
                sprite.setTexture(shapeBF);
                w=1200;
                h=630;

            }

            private:

                sf::Texture shapeBF;

        };
        /**
         * @brief The Base class
         */
        class Base{

            public:

                /*параметры базы*/
                sf::Sprite sprite;
                sf::Sprite base_roof;
                int health;
                bool live;

                /*координаты бокса взаимодействия с базой*/
                float box_x;
                float box_y;
                float w;
                float h;

            Base(){

                /*Загружаем базу,которую нужно будет оборонять.*/
                /*Также указываем её позицию на карте*/
                imageB.loadFromFile("../external/Sprites/Base.png");
                imageB.createMaskFromColor(sf::Color::White);
                shapeB.loadFromImage(imageB);
                sprite.setTexture(shapeB);
                sprite.setPosition(500,300);

                box_x=514;
                box_y=317;
                w=122;
                h=107;
                health=200;
                live=true;

                /*отдельно загружаем крышу базы в качестве независимого объекта*/
                imageBR.loadFromFile("../external/Sprites/Base_roof.png");
                imageBR.createMaskFromColor(sf::Color::White);
                shapeBR.loadFromImage(imageBR);
                base_roof.setTexture(shapeBR);
                base_roof.setPosition(526,300);

            }

            private:

                sf::Image imageB;
                sf::Texture shapeB;

                sf::Image imageBR;
                sf::Texture shapeBR;

        };

        /**
         * @brief The Hero class
         */
        class Hero{

            public:

                /*параметры героя*/
                sf::Sprite sprite;
                float h;
                float w;
                float speed;
                int health;
                bool live;

                /*направление ствола танка*/
                int gun_direction;

                /*координаты точки спавна пули после выстрела*/
                float pos_gun_dir_x;
                float pos_gun_dir_y;

            Hero(){

                heroImage.loadFromFile("../external/Sprites/hero.png");
                heroImage.createMaskFromColor(sf::Color(255,255,255));
                heroTexture.loadFromImage(heroImage);
                sprite.setTexture(heroTexture);
                sprite.setPosition(200,200);

                h=63;
                w=62;
                health =100;
                gun_direction=2;
                speed=0.2;
                live=true;

                sprite.setTextureRect(sf::IntRect(0,0,w,h));

                pos_gun_dir_x=(sprite.getPosition().x+(float)(w/2));
                pos_gun_dir_y=(sprite.getPosition().y+(float)h);

            }

            private:

                sf::Texture heroTexture;
                sf::Image heroImage;

        };

        /**
         * @brief The Runes class
         * @see Hp_hero, Hp_base, Plus_damage, Coin
         */
        class Runes{

            public:
                /**
                 * @brief The Hp_hero class
                 */
                class Hp_hero{

                    public:

                        /*параметры руны типа "восстановление здоровья героя"*/
                        sf::Sprite sprite;
                        float w;
                        float h;
                        float frames;
                        float current_frame;
                        int regenHP;

                    Hp_hero(){

                        iconHPH.loadFromFile("../external/Sprites/rune_hp_hero.png");
                        iconHPH.createMaskFromColor(sf::Color::White);
                        shapeHPH.loadFromImage(iconHPH);
                        sprite.setTexture(shapeHPH);

                        w=53;
                        h=50;
                        frames=5;
                        current_frame=0;
                        regenHP=5;

                        sprite.setTextureRect(sf::IntRect(0,0,w,h));

                    }

                    private:

                        sf::Image iconHPH;
                        sf::Texture shapeHPH;

                };
                /**
                 * @brief The Hp_base class
                 */
                class Hp_base{

                    public:

                        /*параметры руны типа "восстановление здоровья базы"*/
                        sf::Sprite sprite;
                        float w;
                        float h;
                        float frames;
                        float current_frame;
                        int regenHP;

                    Hp_base(){

                        iconHPB.loadFromFile("../external/Sprites/rune_hp_base.png");
                        iconHPB.createMaskFromColor(sf::Color::White);
                        shapeHPB.loadFromImage(iconHPB);
                        sprite.setTexture(shapeHPB);

                        w=53;
                        h=50;
                        frames=5;
                        current_frame=0;
                        regenHP=10;

                        sprite.setTextureRect(sf::IntRect(0,0,w,h));

                    }

                    private:

                        sf::Image iconHPB;
                        sf::Texture shapeHPB;

                };
                /**
                 * @brief The Plus_damage class
                 */
                class Plus_damage{

                    public:

                        /*параметры руны типа "добавочный урон героя"*/
                        sf::Sprite sprite;
                        float w;
                        float h;
                        float frames;
                        float current_frame;
                        int addedDamage;

                    Plus_damage(){

                        iconDD.loadFromFile("../external/Sprites/rune_plus_damage.png");
                        iconDD.createMaskFromColor(sf::Color(255,0,0));
                        shapeDD.loadFromImage(iconDD);
                        sprite.setTexture(shapeDD);

                        w=47;
                        h=47;
                        frames=10;
                        current_frame=0;
                        addedDamage=5;

                        sprite.setTextureRect(sf::IntRect(0,0,w,h));

                    }

                    private:

                        sf::Image iconDD;
                        sf::Texture shapeDD;

                };
                /**
                 * @brief The Coin class
                 *
                 */
                class Coin{

                    public:

                        /*параметры руны типа "монетка"*/
                        sf::Sprite sprite;
                        float w;
                        float h;
                        float frames;
                        float current_frame;
                        int value;

                    Coin(){

                        iconC.loadFromFile("../external/Sprites/rune_point.png");
                        iconC.createMaskFromColor(sf::Color(0,255,0));
                        shapeC.loadFromImage(iconC);
                        sprite.setTexture(shapeC);

                        w=47;
                        h=47;
                        frames=10;
                        current_frame=0;
                        value=1;

                        sprite.setTextureRect(sf::IntRect(0,0,w,h));

                    }

                    private:

                        sf::Image iconC;
                        sf::Texture shapeC;

                };

                /*меняем кадр выводимой руны для анимации*/
                void update_frame(int &type){

                    float* current_frame;
                    float frames;
                    float rune_w;
                    float rune_h;
                    sf::Sprite* rune_sprite;

                    switch (type) {
                        case 0:{current_frame=&hp_base.current_frame;frames=hp_base.frames;rune_w=hp_base.w;rune_h=hp_base.h;rune_sprite=&hp_base.sprite;break;}
                        case 1:{current_frame=&hp_hero.current_frame;frames=hp_hero.frames;rune_w=hp_hero.w;rune_h=hp_hero.h;rune_sprite=&hp_hero.sprite;break;}
                        case 2:{current_frame=&plus_damage.current_frame;frames=plus_damage.frames;rune_w=plus_damage.w;rune_h=plus_damage.h;rune_sprite=&plus_damage.sprite;break;}
                        case 3:{current_frame=&coin.current_frame;frames=coin.frames;rune_w=coin.w;rune_h=coin.h;rune_sprite=&coin.sprite;break;}
                        default:{type=-1;return;}
                    }

                    (*current_frame)++;

                    if((*current_frame)>=frames){

                        (*current_frame)=0;
                        rune_sprite->setTextureRect(sf::IntRect(0,0,rune_w,rune_h));

                    }else{

                        rune_sprite->setTextureRect(sf::IntRect(rune_w*(*current_frame),0,rune_w,rune_h));

                    }

                }


                Hp_hero hp_hero;
                Hp_base hp_base;
                Plus_damage plus_damage;
                Coin coin;

        };
        /**
         * @brief The Bullet class
         */
        class Bullet{

            public:

                /*параметры пули*/
                sf::Sprite sprite;
                int damage;
                bool draw;
                float speed;
                int direction;
                float w;
                float h;

                /*парметры взрыва во время выстрела*/
                sf::Sprite explosion;
                int shot;

            Bullet(){

                damage=5;
                h=16;
                w=16;
                speed=0.5;

                sprite.setOrigin((float)(w/2),(float)(h/2));

                /*формируем спрайт взрыва*/
                imageExp.loadFromFile("../external/Sprites/explosion.png");
                imageExp.createMaskFromColor(sf::Color::White);
                shapeExp.loadFromImage(imageExp);
                explosion.setTexture(shapeExp);

                shot=-1;

            }

            Bullet(int dir,float x, float y){


                if(dir==1||dir==3)
                    sprite.setPosition(x,y-5);
                else
                    sprite.setPosition(x,y);

                direction=dir;
                damage=5;
                h=16;
                w=16;
                speed=0.5;

                sprite.setOrigin((float)(w/2),(float)(h/2));

            }

            /*обновляем позицию вывода взрыва при выстреле героя*/
            void update_explosion_coord(float x,float y,int gun_dir){

                switch (gun_dir) {
                    case 0:{explosion.setOrigin(12,22); break;}
                    case 1:{explosion.setOrigin(0,18);break;}
                    case 2:{explosion.setOrigin(12,10);break;}
                    case 3:{explosion.setOrigin(24,18);break;}
                }

                explosion.setPosition(x,y);

            }


            void load_sprite(){

                /*формируем спрайт пули*/
                imageBul.loadFromFile("../external/Sprites/bullet.png");
                imageBul.createMaskFromColor(sf::Color::White);
                shapeBul.loadFromImage(imageBul);
                sprite.setTexture(shapeBul);

            }

            private:

                sf::Image imageBul;
                sf::Texture shapeBul;

                sf::Image imageExp;
                sf::Texture shapeExp;

        };
        /**
         * @brief The BaseExplosion class
         */
        class BaseExplosion{
            public:

                /*параметры взрыва*/
                sf::Sprite sprite;
                float w;
                float h;

                float row;
                float colomn;

            BaseExplosion(){

                row=0;
                colomn=0;

                w=170;
                h=185;

                imageBE.loadFromFile("../external/Sprites/base_explosion.png");
                imageBE.createMaskFromColor(sf::Color(255,255,255));
                shapeBE.loadFromImage(imageBE);
                sprite.setTexture(shapeBE);

                sprite.setTextureRect(sf::IntRect(colomn*w,row*h,w,h));
                sprite.setPosition(500,275);

            }

            /*обновляем кадр взрыва*/
            bool updateFrame(){

                int flag=false;
                colomn++;

                if(colomn==4){

                    colomn=0;
                    row++;

                }

                if((row==1) || (colomn==3)){

                    flag=true;

                }

                sprite.setTextureRect(sf::IntRect(colomn*w,row*h,w,h));

                return flag;

            }

            private:

                sf::Image imageBE;
                sf::Texture shapeBE;

        };

        /**
         * @brief The HeroExplosion class
         */
        class HeroExplosion{

            public:

                /*параметры взрыва*/
                sf::Sprite sprite;
                float w;
                float h;

                float colomn;

            HeroExplosion(){

                colomn=0;

                w=85;
                h=69;

                imageHE.loadFromFile("../external/Sprites/hero_explosion.png");
                imageHE.createMaskFromColor(sf::Color(255,255,255));
                shapeHE.loadFromImage(imageHE);
                sprite.setTexture(shapeHE);

                sprite.setTextureRect(sf::IntRect(colomn*w,0,w,h));

            }

            /*обновляем кадр взрыва*/
            bool updateFrame(){

                bool flag=false;
                colomn++;

                if(colomn==6){

                    flag=true;

                }

                sprite.setTextureRect(sf::IntRect(colomn*w,0,w,h));

                return flag;

            }

            private:

                sf::Image imageHE;
                sf::Texture shapeHE;

        };

        /**
         * @brief The Enemys class
         *
         * @todo Очень слабо реализована масштабируемость класс. Требуется упростить способ добавления новых объектов в качестве врагов.
         */
        class Enemys{

            public:

                /*дополнительный класс врага для хранения второстепенных данный*/
                class EnemyUpdates{

                    public:

                        float enemySPAWNtime;

                        int addedDamagePerRoundInPercentage;
                        int addedHealthPerRoundInPercentage;

                        float w;
                        float h;

                    EnemyUpdates(){

                        enemySPAWNtime=0;

                        addedDamagePerRoundInPercentage=0;
                        addedHealthPerRoundInPercentage=0;

                        w=60;
                        h=60;

                    }

                };

                class EnemyTemlate{

                    public:

                        /*параметры врага*/
                        sf::Sprite sprite;
                        int health;
                        int EHP;
                        int damage;
                        float speed;

                        int enemyType;

                        float row;
                        float colomn;

                        float frame_x;
                        float frame_y;
                        float frame_w;
                        float frame_h;

                        bool framesComplited;

                        /*параметры движения врага по карте*/
                        float enemyUPDATEframeTime;

                        sf::Vector2f vectorToTarget;

                        sf::Vector2f targetPosition;
                        int typeSide;

                        bool StayToDealDamage;
                        bool StayToTakeDamage;

                        /*параметры для конкретных типов врагов*/

                        float enemyHOLD_RUNtime;
                        bool flagTOhold;

                        float enemyINVIS_RUNtime;
                        bool invisibility;

                        float enemyRESIST_RUNtime;
                        bool damageResist;
                        int cutDamageValue;

                        void loadSprite(int enemyIndex,int frme_x,int frme_y,int frme_w,int frme_h){

                            switch (enemyIndex) {
                                case 0:{imageE.loadFromFile("../external/Sprites/enemy_butch.png");break;}
                                case 1:{imageE.loadFromFile("../external/Sprites/enemy_bat.png");break;}
                                case 2:{imageE.loadFromFile("../external/Sprites/enemy_heap.png");break;}
                                case 3:{imageE.loadFromFile("../external/Sprites/enemy_bull.png");break;}
                                case 4:{imageE.loadFromFile("../external/Sprites/enemy_mud_drop.png");break;}
                                case 5:{imageE.loadFromFile("../external/Sprites/enemy_mushroom.png");break;}
                            }

                            imageE.createMaskFromColor(sf::Color(255,255,255));
                            shapeE.loadFromImage(imageE);
                            sprite.setTexture(shapeE);
                            sprite.setTextureRect(sf::IntRect(frme_x,frme_y,frme_w,frme_h));

                        }

                        /*инициализация параметров врагов:здоровья и атаки*/
                        void loadEnemyParametrs(int enemyIndex,int &addedDmgInPerct,int &addedHpInPerct){

                            switch (enemyIndex) {
                                case 0:{EHP=40;damage=10;speed=0.05;break;}
                                case 1:{EHP=20;damage=5;speed=0.08;break;}
                                case 2:{EHP=80;damage=10;speed=0.02;break;}
                                case 3:{EHP=80;damage=15;speed=0.02;enemyHOLD_RUNtime=0;flagTOhold=false;break;}
                                case 4:{EHP=20;damage=5;speed=0.05;enemyINVIS_RUNtime=0;invisibility=false;break;}
                                case 5:{EHP=40;damage=10;speed=0.02;enemyRESIST_RUNtime=0;damageResist=false;cutDamageValue=80;break;}
                            }

                            EHP+=((addedHpInPerct*EHP)/100);
                            health=EHP;

                            damage+=((addedDmgInPerct*damage)/100);

                        }

                         void updateMOVEframe(){

                            if(row!=4){

                                row=4;
                                colomn=0;

                            }else{

                                colomn++;

                            }

                            if( enemyType==0 || enemyType==3 || enemyType==5){

                                if(colomn>=6)
                                    colomn=0;

                            }else if(enemyType==1 || enemyType==2 || enemyType==4){

                                if(colomn>=4)
                                    colomn=0;
                            }

                            loadFrameParametrs();

                        }

                        bool updateIDLEframe(){

                            bool idle=false;

                            if(row!=3){

                                row=3;
                                colomn=0;

                            }else{

                                colomn++;

                            }


                            if(colomn>=4){

                                idle=true;
                                colomn=0;
                                return idle;

                            }

                            loadFrameParametrs();

                            return idle;

                        }

                        bool updateATTACKframe(){

                            bool dealDamage=false;

                            if(row!=0){

                                row=0;
                                colomn=0;

                            }else{

                                colomn++;

                            }

                            if(colomn>=4){

                                colomn=0;
                                dealDamage=true;
                                return dealDamage;

                            }

                            loadFrameParametrs();

                            return dealDamage;

                        }

                        bool updateDEATHframe(){

                            bool die=false;

                            if(row!=1){

                                row=1;
                                colomn=0;

                            }else{

                                colomn++;

                            }

                            if(enemyType==3 && colomn>=6){

                                die=true;
                                return die;

                            }else if( (enemyType==0|| enemyType==1 ||enemyType==2 || enemyType==4||enemyType==5) && colomn>=4){

                                die=true;
                                return die;

                            }

                            loadFrameParametrs();

                            return die;

                        }

                        bool updateHURTframe(){

                            bool takeDamage=false;

                            if(row!=2){

                                row=2;
                                colomn=0;

                            }else{

                                colomn++;

                            }

                            if( (enemyType==1 || enemyType==4) && colomn>=2){

                                takeDamage=true;
                                return takeDamage;

                            }else if( (enemyType==0||enemyType==2 || enemyType==3||enemyType==5) && colomn>=4){

                                takeDamage=true;
                                return takeDamage;

                            }

                            loadFrameParametrs();

                            return takeDamage;

                        }

                        /*формаируем параметры выводимого кадра из спрайта врага*/
                        void loadFrameParametrs(){

                            switch (typeSide) {
                                case 0:{

                                    if(vectorToTarget.x>=0){

                                        frame_x=colomn*60+60;frame_y=row*60;frame_w=-60;frame_h=60;

                                    }else{

                                        frame_x=colomn*60;frame_y=row*60;frame_w=60;frame_h=60;

                                    }

                                    break;
                                }
                                case 1:{frame_x=colomn*60;frame_y=row*60;frame_w=60;frame_h=60;break;}
                                case 2:{

                                    if(vectorToTarget.x>=0){

                                        frame_x=colomn*60+60;frame_y=row*60;frame_w=-60;frame_h=60;

                                    }else{

                                        frame_x=colomn*60;frame_y=row*60;frame_w=60;frame_h=60;

                                    }

                                    break;
                                }
                                case 3:{frame_x=colomn*60+60;frame_y=row*60;frame_w=-60;frame_h=60;break;}
                            }

                            if(damageResist && enemyType==5){
                                frame_x+=(6*60);
                            }

                        }

                        EnemyTemlate(int enemyIndex, float enemy_x, float enemy_y,float target_x,float target_y,float index,int &addedDmgInPerct,int &addedHpInPerct){

                            targetPosition.x=target_x;
                            targetPosition.y=target_y;

                            vectorToTarget.x=target_x-enemy_x;
                            vectorToTarget.y=target_y-enemy_y;

                            typeSide=index;
                            enemyType=enemyIndex;
                            StayToDealDamage=false;
                            StayToTakeDamage=false;

                            enemyUPDATEframeTime=0;
                            framesComplited=false;

                            colomn=0;
                            row=4;

                            loadFrameParametrs();

                            loadSprite(enemyIndex,frame_x,frame_y,frame_w,frame_h);

                            loadEnemyParametrs(enemyIndex,addedDmgInPerct,addedHpInPerct);

                            sprite.setPosition(enemy_x,enemy_y);

                        }

                    private:

                        sf::Texture shapeE;
                        sf::Image imageE;

                };


        };



        Map map;

        Base base;
        BaseExplosion baseExplosion;

        Hero hero;
        HeroExplosion heroExplosion;

        Runes rune;

        Bullet bullet;
        std::vector<Bullet> bullets;

        Enemys::EnemyUpdates enemyUpdates;
        std::vector<Enemys::EnemyTemlate> enemy;

};

#endif // GAME_OBJECTS_H
