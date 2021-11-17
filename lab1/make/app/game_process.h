#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include <SFML/Graphics.hpp>
#include <random>

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"
#include "game_end_window.h"

/**
 * \defgroup mainLoop Главные функции игрового цикла
 */

/**
 * \defgroup menu Отрисовка окон меню игры
 */

/**
 * \defgroup heroBaseHandler Обработчики главного героя и базы
 */

/**
 * \defgroup enemyHandler Обработчики противников
 */

/**
 * \defgroup runeHandler Обработчики рун
 */


/**
 * @ingroup mainLoop
 * @brief Вывод игрового процесса в игровом окне
 *
 *
 * @param window окно игры
 * @param upperParametr объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param lowerParametr объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param object класса GameObjects с игровыми объектами
 * @return none
 */
void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object);

/**
 * @ingroup heroBaseHandler
 * @brief Передвижение главного героя в окне игрового процесса
 *
 * @param object класса GameObjects с игровыми объектами
 * @param time врямя работы предыдущего цикла игры
 * @param flag флаг для тестирования функции
 * @return none
 */
void move_hero(GameObject &object ,float time,int flag);

/**
 * @ingroup enemyHandler
 * @brief Обработка движений противников по карте игрового процесса
 * @todo Требуется улучшить обработчик взаимодействия с объектами на карте
 *
 * @param object класса GameObjects с игровыми объектами
 * @param time врямя работы предыдущего цикла игры
 * @return none
 */
void move_enemy(GameObject &object, float time,std::minstd_rand &simple_rand);

/**
 * @ingroup heroBaseHandler
 * @brief Обработка выстрелов главного героя и последующее отслеживание взаимодействий пули с объектами
 *
 * @param object класса GameObjects с игровыми объектами
 * @param menubar объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param toolbar объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param time врямя работы предыдущего цикла игры
 * @param window окно игры
 * @return none
 */
void hero_shot(GameObject &object,MenuBar &menubar,ToolBar &toolbar,float time,sf::RenderWindow &window);

/**
 * @ingroup enemyHandler
 * @brief Обработка атаки врагов на карте игрового процесса
 *
 * @param object класса GameObjects с игровыми объектами
 * @param toolbar объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param time врямя работы предыдущего цикла игры
 */
void enemy_hit(GameObject &object,ToolBar &toolbar,float time);

/**
 * @ingroup menu
 * @brief Остановка игры и вывод меню-паузы
 *
 * @param window окно игры
 * @param upperParametr объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param lowerParametr объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param cursor объект класса Cursors  для отображения кастомного курсора в ркне игры
 * @param object класса GameObjects с игровыми объектами
 * @param globalTime таймер игры
 * @param gameTime таймер для привязки к передвижениям игровых объектов с целью снижения нагрузки на прцессор
 * @return флаг о нажатой кнопке в меню "Пауза":
 * true-была нажата кнопка "выход в главное меню",
 * false-была нажата кнопка "продолжить игру"
 */
bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime,sf::Clock &gameTime);

/**
 * @ingroup menu
 * @brief Обработка нажатий кнопок мыши
 *
 * @param menubar объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param cursor объект класса Cursors  для отображения кастомного курсора в ркне игры
 * @param window окно игры
 * @return флаг о нажатии кнопки паузы:
 * true-кнопка нажата,
 * false-кнопка не нажата
 */
bool mouse_click(MenuBar &menubar,Cursors &cursor,sf::RenderWindow &window);

/**
 * @ingroup menu
 * @brief Обработка завершения игрового цроцесса
 *
 * @param object класса GameObjects с игровыми объектами
 * @param endWindow
 * @return флаг о заверщении игры:
 * true-игра завершина,
 * false-игра продолжается
 */
bool end_game(GameObject &object,GameEndWindow &endWindow);

/**
 * @ingroup menu
 * @brief Вывод диалогового окна "конец игры"
 *
 * @param window окно игры
 * @param endWindow объект класса GameEndWindow c параметрами диалогового окна, выводимого при завершении игры
 * @param upperParametr объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param lowerParametr объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param cursor объект класса Cursors  для отображения кастомного курсора в ркне игры
 * @param object класса GameObjects с игровыми объектамим
 * @param globalTime таймер игры
 * @param gameTime таймер для привязки к передвижениям игровых объектов с целью снижения нагрузки на прцессор
 * @return none
 */
void game_end_window(sf::RenderWindow &window,GameEndWindow &endWindow,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime);

/**
 * @ingroup runeHandler
 * @brief Анимация руны и её вывод на карту игрового процесса
 *
 * @param object класса GameObjects с игровыми объектами
 * @param toolbar объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param runeUPDATEtime время с прошлого спавна руны
 * @param time врямя работы предыдущего цикла игры
 * @param simple_rand рандомайзер для получения случайных велечин
 * @return none
 */
void update_spawn_rune(GameObject &object,ToolBar &toolbar,float &runeUPDATEtime,float &time,std::minstd_rand &simple_rand);

/**
 * @ingroup heroBaseHandler
 * @brief Отрисовка и анимация взрыва базы
 *
 * @param window окно игры
 * @param upperParametr объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @param lowerParametr объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param cursor объект класса Cursors  для отображения кастомного курсора в ркне игры
 * @param object класса GameObjects с игровыми объектами
 * @param gamelTime таймер для привязки к передвижениям игровых объектов с целью снижения нагрузки на прцессор
 * @return none
 */
void base_hero_explosion(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &gameTime);

/**
 * @ingroup runeHandler
 * @brief Обработка взаимодействия главного героя с заспавненной руной на карте игрового процесса
 *
 * @param object класса GameObjects с игровыми объектами
 * @param toolbar объект класса Toolbar с параметрами нижней полоски(тулбара) на экране игрового процесса
 * @param menubar объект класса MenuBar с параметрами верхней полоски полоски(меню бара) на экране игрового процесса
 * @return none
 */
void take_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar);

#endif // GAME_PROCESS_H
