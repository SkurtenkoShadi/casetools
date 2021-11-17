#ifndef UPDATE_SPAWN_RUNE_H
#define UPDATE_SPAWN_RUNE_H

#include "game_objects.h"
#include "tool_bar.h"

/**
 * @ingroup runeHandler
 * @brief Выбираются случайным образом координаты руны для отображения на карте
 *
 * @param object  объект класса GameObjects с игровыми объектами
 * @param toolbar объект класса ToolBar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param simple_rand рандомайзер для получения случайных велечин
 * @return none
 */
void randomize_rune_coordinates(GameObject &object,ToolBar &toolbar,std::minstd_rand &simple_rand);

#endif // UPDATE_SPAWN_RUNE_H
