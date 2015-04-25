#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>

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
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    //contains list of all objects which bullet is colliding with
    for (int i=0, n=colliding_items.size(); i<n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;//escape this member fcn if enemy is deleted
        }
    }

    //move bullet up
    setPos(x(),y()-10);
    //delete bullet object if off the scene
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;

    }
}

