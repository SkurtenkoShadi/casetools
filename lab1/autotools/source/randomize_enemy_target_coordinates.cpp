#include<SFML/Graphics.hpp>
#include"game_objects.h"

sf::Vector2f randomize_enemy_target_coordinates(GameObject &object,float typePosition,std::minstd_rand &simple_rand){

    sf::Vector2f targetCoordinates;

    unsigned long w=(simple_rand()%(int)object.base.w);
    unsigned long h=(simple_rand()%(int)object.base.h);

    switch (int(typePosition)) {
        case 0:{targetCoordinates.x=((float)w+object.base.box_x);targetCoordinates.y=object.base.box_y-object.enemyUpdates.h;break;}
        case 1:{targetCoordinates.x=object.base.box_x+object.base.w;targetCoordinates.y=((float)h+object.base.box_y);break;}
        case 2:{targetCoordinates.x=((float)w+object.base.box_x);targetCoordinates.y=object.base.box_y+object.base.h;break;}
        case 3:{targetCoordinates.x=object.base.box_x-object.enemyUpdates.w;targetCoordinates.y=((float)h+object.base.box_y);break;}
    }

    return targetCoordinates;

}
