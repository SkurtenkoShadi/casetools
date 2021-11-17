#include <SFML/Graphics.hpp>
#include "game_objects.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include <vector>

void enemy_hit(GameObject &object,ToolBar &toolbar,float time){

    /*обработка наненсения урона противниками*/
    for(std::vector<GameObject::Enemys::EnemyTemlate>::iterator it=object.enemy.begin();it!=object.enemy.end();it++){

        /*если герой находится в зоне нанесения урона противником*/
        if(sf::IntRect(it->sprite.getPosition().x,it->sprite.getPosition().y,62,62).contains(object.hero.pos_gun_dir_x,object.hero.pos_gun_dir_y)&&it->health>0){

            it->StayToDealDamage=true;

        /*если противник дошёл до целевой точки*/
        }else if(it->vectorToTarget.x==0 && it->vectorToTarget.y==0 && !it->StayToTakeDamage){

            it->enemyUPDATEframeTime+=time;
            if(it->enemyUPDATEframeTime>100){

               it->enemyUPDATEframeTime=0;
               it->framesComplited=it->updateATTACKframe();

            }

            if(it->framesComplited){

                /*отнимаем здоровье у базы*/
                toolbar.change_hero_base_hp("base","damaging",it->damage,object.base.health);
                it->framesComplited=false;

            }

        }else{

            it->StayToDealDamage=false;

        }

        if(it->StayToDealDamage){

            it->enemyUPDATEframeTime+=time;
            if(it->enemyUPDATEframeTime>100){

               it->enemyUPDATEframeTime=0;
               it->framesComplited=it->updateATTACKframe();

            }

            if(it->framesComplited){

                /*отнимаем здоровье у героя*/
                toolbar.change_hero_base_hp("hero","damaging",it->damage,object.hero.health);
                it->StayToDealDamage=false;
                it->framesComplited=false;

            }

        }

    }

}
