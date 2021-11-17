#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object){

     /*отрисовываем элементы в окне*/
     window.clear();

     /*игровое поле и его объекты*/
     window.draw(object.map.sprite);
     window.draw(object.base.sprite);
     window.draw(object.hero.sprite);

     switch (lowerParametr.typeRandomedRune) {
         case 0 : {window.draw(object.rune.hp_base.sprite); break;}
         case 1 : {window.draw(object.rune.hp_hero.sprite); break;}
         case 2 : {window.draw(object.rune.plus_damage.sprite); break;}
         case 3 : {window.draw(object.rune.coin.sprite); break;}
     }

     for(std::vector<GameObject::Bullet>::iterator it=object.bullets.begin();it!=object.bullets.end();it++){

         it->load_sprite();

         window.draw(it->sprite);

     }

    /*если был выстрел,то нужно отобразить взрыв*/
    if(object.bullet.shot<5 && object.bullet.shot!=-1){

        object.bullet.shot++;

        if(object.bullet.shot>5){

            object.bullet.shot=-1;

        }

        object.bullet.update_explosion_coord(object.hero.pos_gun_dir_x,object.hero.pos_gun_dir_y,object.hero.gun_direction);

        window.draw(object.bullet.explosion);

    }

    for(std::vector<GameObject::Enemys::EnemyTemlate>::iterator it=object.enemy.begin();it!=object.enemy.end();it++){

        if(it->enemyType==4 &&it->invisibility &&it->framesComplited){

            continue;

        }

        it->loadSprite(it->enemyType,it->frame_x,it->frame_y,it->frame_w,it->frame_h);

        window.draw(it->sprite);

    }

    window.draw(object.base.base_roof);

    /*меню бар с его датчиками*/
    window.draw(upperParametr.menubarline);

    window.draw(upperParametr.pauseButton);
    window.draw(upperParametr.pauseButtonText);

    window.draw(upperParametr.roundText);

    window.draw(upperParametr.iconCounterAddedDamage);
    window.draw(upperParametr.basis_damage);
    window.draw(upperParametr.textCounterAddedDamage);

    window.draw(upperParametr.iconCounterCoins);
    window.draw(upperParametr.textCounterCoins);


    /*тул бар с его датчиками*/
    window.draw(lowerParametr.toolbarline);

    window.draw(lowerParametr.timer);
    window.draw(lowerParametr.spawnTimer);

    window.draw(lowerParametr.iconClock);

    window.draw(lowerParametr.hp_hero_red);
    window.draw(lowerParametr.hp_hero_green);
    window.draw(lowerParametr.textHHP);
    window.draw(lowerParametr.iconHPhero);
    window.draw(lowerParametr.valueHHPof);

    window.draw(lowerParametr.hp_base_red_orange);
    window.draw(lowerParametr.hp_base_green);
    window.draw(lowerParametr.textBHP);
    window.draw(lowerParametr.iconHPbase);
    window.draw(lowerParametr.valueBHPof);

    window.draw(lowerParametr.iconEnemy);

    if(lowerParametr.drawIconDeadEnemy){

        window.draw(lowerParametr.iconDeadEnemy);

    }

    window.draw(lowerParametr.hp_enemy_red);
    window.draw(lowerParametr.hp_enemy_green);
    window.draw(lowerParametr.textEHP);
    window.draw(lowerParametr.iconHPenemy);
    window.draw(lowerParametr.valueEHPof);

    window.draw(lowerParametr.iconTimer);

}
