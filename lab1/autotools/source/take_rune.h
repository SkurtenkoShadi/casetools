#ifndef TAKE_RUNE_H
#define TAKE_RUNE_H

#include "game_objects.h"
#include "tool_bar.h"
#include "menu_bar.h"

/**
 * @ingroup runeHandler
 * @brief Обрабатывается эффект применения руны в соответствии с её типом
 *
 *@param объект класса GameObjects с игровыми объектами
 *@param toolbar объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 *@param menubar объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 *@return none
 */
void effect_of_the_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar);

#endif // TAKE_RUNE_H
