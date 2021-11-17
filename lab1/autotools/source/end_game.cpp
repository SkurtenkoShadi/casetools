#include <SFML/Graphics.hpp>
#include "game_objects.h"
#include "game_end_window.h"

bool end_game(GameObject &object,GameEndWindow &endWindow){

    bool endFlag=false;

    /*если база разбита,то ставим флаг о выводе взрыва объекта и завершении игры*/
    if(object.base.health==0){

        endWindow.setDescription(true);
        object.base.live=false;
        endFlag=true;

    }

    /*если герой погиб,то ставим флаг о выводе взрыва объекта и завершении игры*/
    if(object.hero.health==0){

        endWindow.setDescription(false);
        object.heroExplosion.sprite.setPosition(object.hero.sprite.getPosition().x,object.hero.sprite.getPosition().y);
        object.hero.live=false;
        endFlag=true;

    }

    return endFlag;

}
