#include "pause_end_menu.h"
#include "game_end_window.h"

void game_end_window(sf::RenderWindow &window,GameEndWindow &endWindow,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime){

    endWindow.update_timer();
    upperParametr.pauseButtonText.setColor(sf::Color::Black);

    while(endWindow.secondsTillExit>0){

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition((float)Mouse.x,(float)Mouse.y);

        endWindow.check_timer(globalTime);

        game_draw(window,upperParametr,lowerParametr,object);

        window.draw(endWindow.sprite);
        window.draw(endWindow.description);
        window.draw(endWindow.timer);

        window.draw(cursor.cursore);
        window.display();

    }

}
