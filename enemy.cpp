#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int

#include <QDebug>
Enemy::Enemy() {
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //drew the Enemy
    setRect(45,-50, 100,100); //(x,y,width,height)

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
    if(pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    qDebug() <<"enemy deleted";
    }
}

