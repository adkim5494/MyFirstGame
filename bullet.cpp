#include "bullet.h"
#include <QTimer>

Bullet::Bullet() {
    //drew the bullet
    setRect(45,-50, 10,50); //(x,y,width,height)

    //every time timer goes off, it calls move function of bullet
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //initialize the timer, 50 miliseconds
    timer->start(50);
}

void Bullet::move(){
    //move bullet up
    setPos(x(),y()-10);
}

