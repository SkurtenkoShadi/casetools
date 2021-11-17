#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>
#include "cursors.h"
#include <iostream>

/**
 * @ingroup mainLoop
 * @brief Главный цикл игрового процесса
 *
 * @param window окно игры
 * @param cursor объект класса Cursors с кастомным курсором
 * @return none
 */
void game_process(sf::RenderWindow &window, Cursors &cursor);

#endif // MAIN_H
