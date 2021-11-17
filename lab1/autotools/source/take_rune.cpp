#include "take_rune.h"

void take_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar){

    /*координаты прямоугольника,в котором расположена руна*/
    sf::Vector2f x_y_cord;
    float h=0;
    float w=0;

    /*определяем тип заспавненной руны и записываем её параметры*/
    switch (toolbar.typeRandomedRune) {
        case 0:{x_y_cord=object.rune.hp_base.sprite.getPosition(); h=object.rune.hp_base.h; w=object.rune.hp_base.w; break;}
        case 1:{x_y_cord=object.rune.hp_hero.sprite.getPosition(); h=object.rune.hp_hero.h; w=object.rune.hp_hero.w; break;}
        case 2:{x_y_cord=object.rune.plus_damage.sprite.getPosition(); h=object.rune.plus_damage.h; w=object.rune.plus_damage.w; break;}
        case 3:{x_y_cord=object.rune.coin.sprite.getPosition(); h=object.rune.coin.h; w=object.rune.coin.w;break;}
        default:{toolbar.typeRandomedRune=-1; return;}
    }

    /*если ствол танка пересёк прямоугольник , в котором расположена руна,то герой её взял*/
    if(sf::IntRect(x_y_cord.x,x_y_cord.y,w,h).contains(object.hero.pos_gun_dir_x,object.hero.pos_gun_dir_y)){

        effect_of_the_rune(object,toolbar,menubar);
        toolbar.typeRandomedRune=-1;
        toolbar.randomizeCoordinates=false;

    }

}
