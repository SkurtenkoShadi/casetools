#include <SFML/Graphics.hpp>
#include "game_objects.h"

sf::Vector3f randomize_enemy_coordinates(GameObject &object,std::minstd_rand &simple_rand){

    sf::Vector3f enemyCoordinates;
    int typePosition;

    int w=object.map.w-object.enemyUpdates.w;
    int h=object.map.h-object.enemyUpdates.h;

    typePosition=simple_rand()%4;

    switch (typePosition){
        case 0:{enemyCoordinates.y=55; enemyCoordinates.x=(float)(simple_rand()%w); break;}
        case 1:{enemyCoordinates.y=(float)((simple_rand()%h)+55); enemyCoordinates.x=(float)w; break;}
        case 2:{enemyCoordinates.y=(float)(h+55); enemyCoordinates.x=(float)(simple_rand()%w); break;}
        case 3:{enemyCoordinates.y=(float)((simple_rand()%h)+55); enemyCoordinates.x=0; break;}
    }

    enemyCoordinates.z=(float)typePosition;

    return enemyCoordinates;

}
