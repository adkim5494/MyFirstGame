#include "Enemy.h"
#include "Score.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int

extern Game* game; //there is an external global object called game

Enemy::Enemy() {
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //drew the Enemy
    setRect(0,0, 100,100); //(x,y,width,height)

    //every time timer goes off, it calls move function of Enemy
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //initialize the timer, 50 miliseconds
    timer->start(50);
}

void Enemy::move(){
    //move Enemy down
    setPos(x(),y()+10);

    //delete Enemy object if off the scene
    if(pos().y() > 600){

        //decrease the health if enemy is off screen
        game->health->decrease_health();

        scene()->removeItem(this);
        delete this;
    }
}

