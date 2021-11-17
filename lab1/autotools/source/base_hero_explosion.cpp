#include"game_objects.h"
#include "pause_end_menu.h"

void base_hero_explosion(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &gameTime){

    float explosionUpdateTime=0;
    float time;

    bool endBaseExplosionFrame=false;
    bool endHeroExplosionFrame=false;

    while( !endBaseExplosionFrame && !endHeroExplosionFrame){

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition((float)Mouse.x,(float)Mouse.y);

        time=(float)gameTime.getElapsedTime().asMicroseconds();
        time=time/800;
        gameTime.restart();

        explosionUpdateTime+=time;
        if(explosionUpdateTime>50){

            explosionUpdateTime=0;

            if(!object.base.live)
                endBaseExplosionFrame=object.baseExplosion.updateFrame();
            if(!object.hero.live)
               endHeroExplosionFrame=object.heroExplosion.updateFrame();

        }

        game_draw(window,upperParametr,lowerParametr,object);

        if(!object.base.live)
            window.draw(object.baseExplosion.sprite);
        if(!object.hero.live)
           window.draw(object.heroExplosion.sprite);

        window.draw(cursor.cursore);
        window.display();

    }

}
