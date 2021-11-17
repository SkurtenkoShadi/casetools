#include "game_objects.h"
#include "tool_bar.h"
#include "menu_bar.h"

void effect_of_the_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar){

    if(toolbar.typeRandomedRune==0){

        toolbar.change_hero_base_hp("base","healing",object.rune.hp_base.regenHP,object.base.health);

    }else if(toolbar.typeRandomedRune==1){

        toolbar.change_hero_base_hp("hero","healing",object.rune.hp_hero.regenHP,object.hero.health);

    }else if(toolbar.typeRandomedRune==2){

        menubar.incr_counter_added_damage(object.rune.plus_damage.addedDamage);

    }else if(toolbar.typeRandomedRune==3){

        menubar.incr_counter_coins(object.rune.coin.value);

    }

}
