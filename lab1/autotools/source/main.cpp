#include "main.h"

/**
 * @brief Отрисовка главного меню
 *
 * @ingroup menu
 */
int main(){

    /*создаём  главное окно*/
    sf::RenderWindow window(sf::VideoMode(1200, 740), "Lonely turret", sf::Style::Close | sf::Style::Titlebar);
    /*включаем вертикальную синхронизацию*/
    window.setVerticalSyncEnabled(true);
    /*задаём частоту кадров в секунду*/
    window.setFramerateLimit(30);

    /*устанавливаем позицию окна на экране монитора*/
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width/2)-600,0);
    window.setPosition(centerWindow);

    sf::Image icon;
    icon.loadFromFile("../external/Sprites/icon_game.png");
    window.setIcon(32,32,icon.getPixelsPtr());

    /*выключаем обычный курсор*/
    window.setMouseCursorVisible(false);
    /*загружаем кастомный курсор*/
    Cursors normalCrs;

    /*номер нажатой кнопки*/
    int NumMenu;

       /*загружаем картинку с текстом об авторе программы*/
       sf::Texture shapeAL;
       shapeAL.loadFromFile("../external/Sprites/Autor.png");
       sf::Sprite about(shapeAL);

        /*загружаем стиль текста*/
        sf::Font font;
        font.loadFromFile("../external/Text/Roboto-Italic.ttf");


        /*загружаем задний фон главного меню для отображения*/
        sf::Texture shapeBGM;
        sf::RectangleShape BackgroundPictureMenu(sf::Vector2f(1200,800));
        shapeBGM.loadFromFile("../external/Sprites/BackgroungMainMenu.png");
        BackgroundPictureMenu.setTexture(&shapeBGM);

        /*загружаем кнопку "Начать игру" для главного меню*/
        sf::Texture shapeNG;
        shapeNG.loadFromFile("../external/Sprites/Button.png");
        sf::Sprite NewGameButton(shapeNG);

        /*устанавливаем позицию кнопки*/
        NewGameButton.setPosition(75,240);

        /*загружаем содержимое кнопки*/
        sf::Text NewGameText;
        NewGameText.setFont(font);
        NewGameText.setString("Start game");
        NewGameText.setPosition(115,255);

        /*загружаем кнопку "Об авторе" для главного меню*/
        sf::Texture shapeAA;
        shapeAA.loadFromFile("../external/Sprites/Button.png");
        sf::Sprite AboutAutorButton(shapeAA);

        /*устанавливаем позицию кнопки*/
        AboutAutorButton.setPosition(75,320);

        /*загружаем содержимое кнопки*/
        sf::Text AboutAutorText;
        AboutAutorText.setFont(font);
        AboutAutorText.setString("About Autor");
        AboutAutorText.setPosition(115,335);

        /*загружаем кнопку "Выход" для главного меню*/
        sf::Texture shapeQ;
        shapeQ.loadFromFile("../external/Sprites/Button.png");
        sf::Sprite QuitButton(shapeQ);

        /*устанавливаем позицию кнопки*/
        QuitButton.setPosition(75,410);

        /*загружаем содержимое кнопки*/
        sf::Text QuitText;
        QuitText.setFont(font);
        QuitText.setString("Exit");
        QuitText.setPosition(115,425);

        bool Exit=false;

        while (!Exit){

            /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
            sf::Vector2i Mouse = sf::Mouse::getPosition(window);
            normalCrs.cursore.setPosition((float)Mouse.x,(float)Mouse.y);

            NumMenu=0;

            /*красим текст кнопок а белый*/
            NewGameText.setFillColor(sf::Color::White);
            AboutAutorText.setFillColor(sf::Color::White);
            QuitText.setFillColor(sf::Color::White);

            /*Если мышь была наведена на одну из кнопок, то меняем цвет текста соответствующей кнопки на чёрный.*/
            /*Также в переменную NumMenu записываем номер кнопки, на которую навели мышь*/
            if (sf::IntRect(75, 240, 221,71 ).contains(sf::Mouse::getPosition(window))){

                 NewGameText.setFillColor(sf::Color::Black);
                 NumMenu=1;

            }

            if (sf::IntRect(75, 320, 221,71 ).contains(sf::Mouse::getPosition(window))){

                AboutAutorText.setFillColor(sf::Color::Black);
                NumMenu=2;

            }

            if (sf::IntRect(75, 410, 221,71 ).contains(sf::Mouse::getPosition(window))){

                QuitText.setFillColor(sf::Color::Black);
                NumMenu=3;

            }

            /*Если была нажата левая кнопка мыши,*/
            /*то проверяем:была ли она нажата в области одной из кнопок*/
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                switch (NumMenu) {
                    case 1:{game_process(window,normalCrs); break;}
                    case 2:{window.draw(about); window.display(); while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){;} break;}
                    case 3:{window.close(); Exit=true;break;}
                }

            }

            /*отрисовка главного меню игры*/
            window.clear();
            window.draw(BackgroundPictureMenu);

            window.draw(NewGameButton);
            window.draw(AboutAutorButton);
            window.draw(QuitButton);

            window.draw(AboutAutorText);
            window.draw(NewGameText);
            window.draw(QuitText);

            window.draw(normalCrs.cursore);

            window.display();

        }

    return 0;

}
