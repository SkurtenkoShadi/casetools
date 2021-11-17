#ifndef MOVE_ENEMY_H
#define MOVE_ENEMY_H
#include "game_objects.h"

/**
 * @ingroup enemyHandler
 * @brief Случайным образом получаем координаты точки,на которой будет заспавнен противник
 *
 * @param object класса GameObjects с игровыми объектамим
 * @param simple_rand рандомайзер для получения случайных велечин
 * @return
 */
sf::Vector3f randomize_enemy_coordinates(GameObject &object,std::minstd_rand &simple_rand);

/**
 * @ingroup enemyHandler
 * @brief Случайным образом получаем кооординаты точки,до которой противник должен дойти
 *
 * @param object класса GameObjects с игровыми объектамим
 * @param typePosition область спавна противника:
 *      0-сверху от базы,
 *      1-справа от базы,
 *      2-снизу от базы,
 *      3-слева от базы
 *
 * @param simple_rand рандомайзер для получения случайных велечин
 * @return
 */
sf::Vector2f randomize_enemy_target_coordinates(GameObject &object,float typePosition,std::minstd_rand &simple_rand);

/**
 * @ingroup enemyHandler
 * @brief Случайным образом получаем тип противника,который будет заспавнен на карте игрового процесса
 *
 * @param object класса GameObjects с игровыми объектамим
 * @param simple_rand рандомайзер для получения случайных велечин
 * @return
 */
int randomize_enemy_type(std::minstd_rand &simple_rand);


#endif // MOVE_ENEMY_H
