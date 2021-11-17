#include<random>

int randomize_enemy_type(std::minstd_rand &simple_rand){

    int enemyType;

    enemyType=simple_rand()%6;

    return enemyType;
}
