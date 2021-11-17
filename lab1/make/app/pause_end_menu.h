#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

/**
 *Вывод игрового процесса в игровом окне
 *
 *@param window окно игры
 *@param upperParametr объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 *@param lowerParametr объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 *@param object объект класса GameObjects с игровыми объектами
 *@return none
 */
void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object);

#endif // PAUSE_MENU_H
