#include<SFML/Graphics.hpp>
#include "menu_bar.h"
#include "cursors.h"

bool mouse_click(MenuBar &menubar,Cursors &cursor,sf::RenderWindow &window){

    bool inBtnField;
    bool pauseFlag=false;

    inBtnField = false;
    menubar.pauseButtonText.setColor(sf::Color::White);

    /*если курсор находиться на кнопке "Пауза"*/
    if (sf::IntRect(menubar.pauseButton.getPosition().x, menubar.pauseButton.getPosition().y, menubar.w,menubar.h ).contains(sf::Mouse::getPosition(window))){

        /*меняем цвет кнопки*/
        menubar.pauseButtonText.setColor(sf::Color::Black);
        inBtnField = true;

    }

    /*Если была нажата левая кнопка мыши,*/
    /*то проверяем:была ли она нажата в области кнопки "Пауза"*/
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

        if (inBtnField){

            pauseFlag=true;

        }

    }

    /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
    sf::Vector2i Mouse = sf::Mouse::getPosition(window);
    cursor.cursore.setPosition((float)Mouse.x,(float)Mouse.y);

        return pauseFlag;

}
