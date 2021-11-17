#include "game_objects.h"
#include <iostream>

void move_hero(GameObject &object,float time,int flag){

    /*если была нажата клавиша "A" или "Cтрелка влево",то осуществляем поворот героя влево*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)||(flag==3)){

        /*загружаем в спрайт танка картинку поворота влево*/
        object.hero.sprite.setTextureRect(sf::IntRect(0,1*object.hero.h,object.hero.w,object.hero.h));


        /*определяем направление ствола танка и позицию спавна снаряда при выстреле*/
        /*значение 3 - ствол направлен влево*/
        object.hero.gun_direction=3;
        object.hero.pos_gun_dir_x=object.hero.sprite.getPosition().x;
        object.hero.pos_gun_dir_y=(object.hero.sprite.getPosition().y+(object.hero.h/2));

        /*проверка на столкновение с левой границой карты*/
        if((object.hero.sprite.getPosition().x-(object.hero.speed*time))<0){

            /*упираемся в левую границу карты*/
            object.hero.sprite.setPosition(0,object.hero.sprite.getPosition().y);

        }else{

            /*проверка столкновения с правой стенкой базы*/
            if(sf::IntRect(object.base.box_x+object.base.w, object.base.box_y, object.map.w-(object.base.box_x+object.base.w), object.base.h).contains((object.hero.sprite.getPosition().x+(object.hero.w*0.5)),(object.hero.sprite.getPosition().y+(object.hero.h*0.5)))
                &&((object.hero.sprite.getPosition().x-(object.base.box_x+object.base.w))<(0.2*time))){

                /*упираемся в правую стенку базы*/
                object.hero.sprite.setPosition((object.base.box_x+object.base.w),object.hero.sprite.getPosition().y);

            }else{

                /*если танк ни с чем не взаимодействует, то прибавляем стандартную скорость*/
                object.hero.sprite.move(-object.hero.speed*time, 0);

            }

        }

    /*если была нажата клавиша "D" или "Cтрелка направо",то осуществляем поворот героя вправо*/
    }else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)||(flag==1)){

        /*загружаем в спрайт танка картинку поворота вправо*/
        object.hero.sprite.setTextureRect(sf::IntRect(0,2*object.hero.h,object.hero.w,object.hero.h));

        /*определяем направление ствола танка и позицию спавна снаряда при выстреле*/
        /*значение 1 - ствол направлен вправо*/
        object.hero.gun_direction=1;
        object.hero.pos_gun_dir_x=(object.hero.sprite.getPosition().x+object.hero.w);
        object.hero.pos_gun_dir_y=(object.hero.sprite.getPosition().y+(object.hero.h/2));

        /*проверка на столкновение с правой границой карты*/
        if(((object.hero.sprite.getPosition().x+object.hero.w)+(object.hero.speed*time))>object.map.w){

            /*упираемся в правую границу карты*/
            object.hero.sprite.setPosition((float)(object.map.w-object.hero.w),object.hero.sprite.getPosition().y);

        }else{

            /*проверка столкновения с левой стенкой базы*/
            if(sf::IntRect(0, object.base.box_y,object.base.box_x, object.base.h).contains((object.hero.sprite.getPosition().x+(object.hero.w*0.5)),(object.hero.sprite.getPosition().y+(object.hero.h*0.5)))
                &&((object.base.box_x-(object.hero.sprite.getPosition().x+object.hero.w))<(object.hero.speed*time))){

                /*упираемся в левую стенку базы*/
                object.hero.sprite.setPosition((object.base.box_x-object.hero.w),object.hero.sprite.getPosition().y);

            }else{

                /*если танк ни с чем не взаимодействует, то прибавляем стандартную скорость*/
                object.hero.sprite.move(object.hero.speed*time, 0);

            }

        }

    /*если была нажата клавиша "W" или "Cтрелка вверх",то осуществляем поворот героя в сторону верхней границы окна*/
    }else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)||(flag==0)) {

        /*загружаем в спрайт танка картинку поворота в сторону верхней границы окна*/
        object.hero.sprite.setTextureRect(sf::IntRect(0,3*object.hero.h,object.hero.w,object.hero.h));

        /*определяем направление ствола танка и позицию спавна снаряда при выстреле*/
        /*значение 0 - ствол направлен вверх*/
        object.hero.gun_direction=0;
        object.hero.pos_gun_dir_x=(object.hero.sprite.getPosition().x+(object.hero.w/2));
        object.hero.pos_gun_dir_y=object.hero.sprite.getPosition().y;


        /*проверка на столкновение с верхней границой карты*/
        if((object.hero.sprite.getPosition().y-55)<(object.hero.speed*time)){

            /*упираемся в верхнюю границу карты*/
            object.hero.sprite.setPosition(object.hero.sprite.getPosition().x,55);

        }else{

            /*проверка столкновения с нижней стенкой базы*/
            if(sf::IntRect(object.base.box_x,(object.base.box_y+object.base.h),object.base.w,((object.map.h+55)-(object.base.box_y+object.base.h))).contains((object.hero.sprite.getPosition().x+(object.hero.w*0.5)),(object.hero.sprite.getPosition().y+(object.hero.h*0.5)))
                &&((object.hero.sprite.getPosition().y-(object.base.box_y+object.base.h))<(object.hero.speed*time))){

               /*упираемся в нижнюю стенку базы*/
               object.hero.sprite.setPosition(object.hero.sprite.getPosition().x,(object.base.box_y+object.base.h));

            }else{

                /*если танк ни с чем не взаимодействует, то прибавляем стандартную скорость*/
                object.hero.sprite.move(0, -object.hero.speed*time);

            }

        }

    /*если была нажата клавиша "S" или "Cтрелка вниз",то осуществляем поворот героя в сторону нижней границы окна*/
    }else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)||(flag==2)) {

        /*загружаем в спрайт танка картинку поворота в сторону нижней границы окна*/
        object.hero.sprite.setTextureRect(sf::IntRect(0,0*object.hero.h,object.hero.w,object.hero.h));

        /*определяем направление ствола танка и позицию спавна снаряда при выстреле*/
        /*значение 2 - ствол направлен вниз*/
        object.hero.gun_direction=2;
        object.hero.pos_gun_dir_x=(object.hero.sprite.getPosition().x+(object.hero.w/2));
        object.hero.pos_gun_dir_y=(object.hero.sprite.getPosition().y+object.hero.h);


        /*проверка на столкновение с нижней границой карты*/
        if(((object.map.h+55)-(object.hero.sprite.getPosition().y+object.hero.h))<(object.hero.speed*time)){

            /*упираемся в нижнюю границу карты*/
            object.hero.sprite.setPosition(object.hero.sprite.getPosition().x,((object.map.h+55)-object.hero.h));

        }else{

            /*проверка столкновения с верхней стенкой базы*/
            if(sf::IntRect(object.base.box_x,0,object.base.w,object.base.box_y).contains((object.hero.sprite.getPosition().x+(object.hero.w*0.5)),(object.hero.sprite.getPosition().y+(object.hero.h*0.5)))
            &&((object.base.box_y-(object.hero.sprite.getPosition().y+object.hero.h))<(object.hero.speed*time))){

                /*упираемся в верхнюю стенку базы*/
                object.hero.sprite.setPosition(object.hero.sprite.getPosition().x,(object.base.box_y-object.hero.h));

            }else{

                /*если танк ни с чем не взаимодействует, то прибавляем стандартную скорость*/
                object.hero.sprite.move(0, object.hero.speed*time);

            }

        }

    }

}
