#include <SFML/Graphics.hpp>
#include "game_objects.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include <vector>

void hero_shot(GameObject &object,MenuBar &menubar,ToolBar &toolbar,float time,sf::RenderWindow &window){

    sf::Event event;
    bool bulletKill;

    /*итератор обработки пуль на карте игровоо процесса*/
    for(std::vector<GameObject::Bullet>::iterator it=object.bullets.begin();it!=object.bullets.end();){

        /*если пуля столкнулась с границе карты игрового процесса*/
        if(!sf::IntRect(object.map.sprite.getPosition().x,(object.map.sprite.getPosition().y+55),object.map.w,(object.map.h-16)).contains(it->sprite.getPosition().x,it->sprite.getPosition().y)){

            /*удаляем пулю из обработчика*/
            object.bullets.erase(it);

         /*если пуля столкнулась с базой*/
         }else if(sf::IntRect((object.base.sprite.getPosition().x+30),(object.base.sprite.getPosition().y+25),87,76).contains(it->sprite.getPosition().x,it->sprite.getPosition().y)){

            /*базе наноситься урон*/
            toolbar.change_hero_base_hp("base","damaging",(it->damage+menubar.counterAddedDamage),object.base.health);
            /*удаляем пулю из обработчика*/
            object.bullets.erase(it);

        }else{

            it++;

        }

    }

    /*Обработка нажатия кнопки выстрела*/
    while (window.pollEvent(event)){

        if (event.type==sf::Event::KeyPressed){

            if(event.key.code == sf::Keyboard::Space){

                object.bullets.push_back(GameObject::Bullet(object.hero.gun_direction,object.hero.pos_gun_dir_x,object.hero.pos_gun_dir_y));
                object.bullet.shot=0;
            }

        }

    }


    /*обработка нанесения урона по врагу*/
    for(std::vector<GameObject::Bullet>::iterator itr=object.bullets.begin();itr!=object.bullets.end();){

        bulletKill=false;

        for(std::vector<GameObject::Enemys::EnemyTemlate>::iterator it=object.enemy.begin();it!=object.enemy.end();it++){

            /*если противник типа 4 невидим,то обрабатывать нанесение урона не нужно*/
            if(it->enemyType==4 && it->invisibility){

                continue;

            }

            if(sf::IntRect(it->sprite.getPosition().x,it->sprite.getPosition().y,62,62).contains(itr->sprite.getPosition().x,itr->sprite.getPosition().y) && it->health>0){

                it->StayToTakeDamage=true;
                it->enemyUPDATEframeTime=0;
                it->colomn=0;

                /*если на противника действует эффект снижения урона от пуль,то пересчитываем нанесённый урон*/
                if(it->enemyType==5 && it->damageResist){

                    it->health-=((it->cutDamageValue*(itr->damage+menubar.counterAddedDamage))/100);

                }else{

                    it->health-=(itr->damage+menubar.counterAddedDamage);

                }

                if(it->health<0){

                    it->health=0;

                }

                /*изменяем полоску здоровья противника*/
                toolbar.change_enemy_hp_line(it->health,it->EHP,it->enemyType);

                /*удаляем данную пулю:она попала по обрабатываемому объекту*/
                object.bullets.erase(itr);
                bulletKill=true;

                break;
            }

        }

        if(bulletKill){

            continue;

        }else{

            itr++;

        }

    }

    for(std::vector<GameObject::Enemys::EnemyTemlate>::iterator it=object.enemy.begin();it!=object.enemy.end();){

        if(it->StayToTakeDamage){

           it->enemyUPDATEframeTime+=time;

           if(it->health==0){

               if(it->enemyUPDATEframeTime>100){

                   it->framesComplited=it->updateDEATHframe();
                   it->enemyUPDATEframeTime=0;

               }

           }else{

               if(it->enemyUPDATEframeTime>50){

                   it->framesComplited=it->updateHURTframe();
                   it->enemyUPDATEframeTime=0;

               }

           }

           if(it->framesComplited){

               it->framesComplited=false;
               it->StayToTakeDamage=false;

               if(it->health==0){

                   object.enemy.erase(it);

               }else{

                   it++;

               }

           }else{

               it++;

           }

        }else{

            it++;

        }

    }

    /*обработка движений пуль на карте игрового процесса*/
    for(std::vector<GameObject::Bullet>::iterator it=object.bullets.begin();it!=object.bullets.end();it++){

        switch(it->direction){
            case 0 : { it->sprite.move(0,-object.bullet.speed*time); break; }
            case 1 : { it->sprite.move(object.bullet.speed*time,0); break; }
            case 2 : { it->sprite.move(0,object.bullet.speed*time); break; }
            case 3 : { it->sprite.move(-object.bullet.speed*time,0); break; }
         }

    }

}
