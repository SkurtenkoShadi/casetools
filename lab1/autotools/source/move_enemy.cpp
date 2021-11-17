#include "move_enemy.h"

void move_enemy(GameObject &object, float time,std::minstd_rand &simple_rand){

    sf::Vector3f randomedEnemyCoordinates;
    sf::Vector2f randomedTargetEnemyCoordinates;
    int typeEnemy;
    int typeMovment;

    /*каждые 5 секунд спавним нового врага*/
    object.enemyUpdates.enemySPAWNtime+=time;
    if(object.enemyUpdates.enemySPAWNtime>=5000){

        object.enemyUpdates.enemySPAWNtime=0;

        randomedEnemyCoordinates=randomize_enemy_coordinates(object,simple_rand);
        randomedTargetEnemyCoordinates=randomize_enemy_target_coordinates(object,randomedEnemyCoordinates.z,simple_rand);
        typeEnemy=randomize_enemy_type(simple_rand);

        switch (typeEnemy) {
            case 0:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
            case 1:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
            case 2:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
            case 3:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
            case 4:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
            case 5:{object.enemy.push_back(GameObject::Enemys::EnemyTemlate(typeEnemy,randomedEnemyCoordinates.x,randomedEnemyCoordinates.y,randomedTargetEnemyCoordinates.x,randomedTargetEnemyCoordinates.y,randomedEnemyCoordinates.z,object.enemyUpdates.addedDamagePerRoundInPercentage,object.enemyUpdates.addedHealthPerRoundInPercentage));break;}
        }

    }



    /*обработка движение противников по карте в зависимости о точки их спавна*/
    for(std::vector<GameObject::Enemys::EnemyTemlate>::iterator it=object.enemy.begin();it!=object.enemy.end();it++){

        if((it->vectorToTarget.x==0 && it->vectorToTarget.y==0) || it->StayToDealDamage || it->health==0 || it->StayToTakeDamage ){

            switch (it->enemyType) {
                case 4:{it->invisibility=false;break;}
            }

            typeMovment=-1;
            continue;

        }

        if(it->enemyType==3){

            it->enemyHOLD_RUNtime+=time;

            if(it->enemyHOLD_RUNtime>=2000 && it->flagTOhold==false){

                it->flagTOhold=true;
                it->enemyHOLD_RUNtime=0;
            }

            if(it->flagTOhold && it->enemyHOLD_RUNtime>=1000){

                it->flagTOhold=false;
                it->enemyHOLD_RUNtime=0;

            }else if(it->flagTOhold){

                it->enemyUPDATEframeTime+=time;
                if(it->enemyUPDATEframeTime>100){

                    it->enemyUPDATEframeTime=0;
                    it->updateIDLEframe();

                }

                continue;

            }
        }


        if(it->enemyType==4){

            it->enemyINVIS_RUNtime+=time;

            if(it->enemyINVIS_RUNtime>=3000 && it->invisibility==false){

                it->invisibility=true;
                it->enemyINVIS_RUNtime=0;
                it->framesComplited=false;

            }

            if(!it->framesComplited){

                it->enemyUPDATEframeTime+=time;
                if(it->enemyUPDATEframeTime>100){

                    it->enemyUPDATEframeTime=0;
                    it->framesComplited=it->updateIDLEframe();

                }

                continue;

            }

            if(it->invisibility&&it->enemyINVIS_RUNtime>=3000){

                it->framesComplited=false;
                it->invisibility=false;
                it->enemyINVIS_RUNtime=0;

            }

        }

        if(it->enemyType==5){

            it->enemyRESIST_RUNtime+=time;

            if(it->enemyRESIST_RUNtime>=3000 && !it->damageResist){

                it->damageResist=true;
                it->enemyRESIST_RUNtime=0;

            }

            if(it->damageResist && it->enemyRESIST_RUNtime>=3000){

                it->damageResist=false;
                it->enemyRESIST_RUNtime=0;

            }
        }


        if(it->vectorToTarget.x==0){

            switch (it->typeSide) {
                case 0:{typeMovment=0; break;}
                case 1:{typeMovment=1; break;}
                case 2:{typeMovment=0; break;}
                case 3:{typeMovment=1; break;}
            }

        }else if(it->vectorToTarget.y==0){

            switch (it->typeSide) {
                case 0:{typeMovment=1; break;}
                case 1:{typeMovment=0; break;}
                case 2:{typeMovment=1; break;}
                case 3:{typeMovment=0; break;}
            }

        }else{

           typeMovment=simple_rand()%6;

           if(typeMovment!=1){
               typeMovment=0;
           }

        }


       it->enemyUPDATEframeTime+=time;
       if(it->enemyUPDATEframeTime>=100){

           it->enemyUPDATEframeTime=0;
           it->updateMOVEframe();

       }

       switch (typeMovment) {
           case 0:{
               switch (it->typeSide){
                   case 0:{
                       if(it->vectorToTarget.y<time*it->speed){
                           it->sprite.move(0,it->vectorToTarget.y);
                           it->vectorToTarget.y=0;
                       }else{
                           it->sprite.move(0,time*it->speed);
                           it->vectorToTarget.y-=time*it->speed;
                       }

                       break;
                   }
                   case 1:{
                       if((-it->vectorToTarget.x)<time*it->speed){
                           it->sprite.move(-it->vectorToTarget.x,0);
                           it->vectorToTarget.x=0;
                       }else{
                           it->sprite.move(-time*it->speed,0);
                           it->vectorToTarget.x-=-time*it->speed;
                       }

                       break;
                   }
                   case 2:{
                       if((-it->vectorToTarget.y)<time*it->speed){
                           it->sprite.move(0,it->vectorToTarget.y);
                           it->vectorToTarget.y=0;
                       }else{
                           it->sprite.move(0,-time*it->speed);
                           it->vectorToTarget.y-=-time*it->speed;
                       }

                       break;
                   }
                   case 3:{
                       if(it->vectorToTarget.x<time*it->speed){
                           it->sprite.move(it->vectorToTarget.x,0);
                           it->vectorToTarget.x=0;
                       }else{
                           it->sprite.move(time*it->speed,0);
                           it->vectorToTarget.x-=time*it->speed;
                       }

                       break;
                   }

                }

               break;
            }
            case 1:{
                switch(it->typeSide){
                    case 0:{
                        if(it->vectorToTarget.x>0){
                            if(it->vectorToTarget.x<time*it->speed){
                                it->sprite.move(it->vectorToTarget.x,0);
                                it->vectorToTarget.x=0;
                            }else{
                                it->sprite.move(time*it->speed,0);
                                it->vectorToTarget.x-=time*it->speed;
                            }

                        }else if(it->vectorToTarget.x<0){
                            if((-it->vectorToTarget.x)<time*it->speed){
                                it->sprite.move(it->vectorToTarget.x,0);
                                it->vectorToTarget.x=0;
                            }else{
                                it->sprite.move(-time*it->speed,0);
                                it->vectorToTarget.x-=-time*it->speed;
                            }
                        }

                        break;
                    }
                    case 1:{
                        if(it->vectorToTarget.y>0){
                            if(it->vectorToTarget.y<time*it->speed){
                                it->sprite.move(0,it->vectorToTarget.y);
                                it->vectorToTarget.y=0;
                            }else{
                               it->sprite.move(0,time*it->speed);
                               it->vectorToTarget.y-=time*it->speed;
                            }
                        }else if(it->vectorToTarget.y<0){
                            if((-it->vectorToTarget.y)<time*it->speed){
                                it->sprite.move(0,it->vectorToTarget.y);
                                it->vectorToTarget.y=0;
                            }else{
                                it->sprite.move(0,-time*it->speed);
                                it->vectorToTarget.y-=-time*it->speed;
                            }
                        }

                        break;
                    }
                    case 2:{
                        if(it->vectorToTarget.x>0){
                            if(it->vectorToTarget.x<time*it->speed){
                                it->sprite.move(it->vectorToTarget.x,0);
                                it->vectorToTarget.x=0;
                            }else{
                                it->sprite.move(time*it->speed,0);
                                it->vectorToTarget.x-=time*it->speed;
                            }
                        }else if(it->vectorToTarget.x<0){
                            if((-it->vectorToTarget.x)<time*it->speed){
                                it->sprite.move(it->vectorToTarget.x,0);
                                it->vectorToTarget.x=0;
                            }else{
                                it->sprite.move(-time*it->speed,0);
                                it->vectorToTarget.x-=-time*it->speed;
                            }
                        }

                        break;
                    }

                    case 3:{
                        if(it->vectorToTarget.y>0){
                            if(it->vectorToTarget.y<time*it->speed){
                                it->sprite.move(0,it->vectorToTarget.y);
                                it->vectorToTarget.y=0;
                            }else{
                                it->sprite.move(0,time*it->speed);
                                it->vectorToTarget.y-=time*it->speed;
                            }
                        }else if(it->vectorToTarget.y<0){
                            if((-it->vectorToTarget.y)<time*it->speed){
                                it->sprite.move(0,it->vectorToTarget.y);
                                it->vectorToTarget.y=0;
                            }else{
                                it->sprite.move(0,-time*it->speed);
                                it->vectorToTarget.y-=-time*it->speed;
                            }
                        }

                        break;
                    }

                }

                break;
            }


       }


    }

}
