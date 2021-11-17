#include "update_spawn_rune.h"

void update_spawn_rune(GameObject &object,ToolBar &toolbar,float &runeUPDATEtime,float &time,std::minstd_rand &simple_rand){

    /*если прошло 60 секунд то выбираем случайные координаты для новой случайной руны*/
    if(toolbar.randomizeCoordinates){

        randomize_rune_coordinates(object,toolbar,simple_rand);

    }else{

        /*иначе продолжаем выводить текущую руну на игровом поле*/
        runeUPDATEtime+=time;
        if(runeUPDATEtime>250){

            runeUPDATEtime=0;
            if(toolbar.typeRandomedRune==0){

                object.rune.update_frame(toolbar.typeRandomedRune);

            }else if(toolbar.typeRandomedRune==1){

                object.rune.update_frame(toolbar.typeRandomedRune);

            }else if(toolbar.typeRandomedRune==2){

                object.rune.update_frame(toolbar.typeRandomedRune);

            }else if(toolbar.typeRandomedRune==3){

                object.rune.update_frame(toolbar.typeRandomedRune);

            }else{

                toolbar.typeRandomedRune=-1;

            }

        }

    }

}
