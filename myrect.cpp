#include "MyRect.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void MyRect::keyPressEvent(QKeyEvent *event){
    //moving the rectangle

    //checking if player is outside of scene boundary
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
        setPos(x()-10,y());
        }
    }

    else if (event->key() == Qt::Key_Right){
        if (pos().x()+100 < 800){
        setPos(x()+10,y());
        }
    }

    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
        setPos(x(),y()-10); //y axis is oriented downward
        }
    }

    else if (event->key() == Qt::Key_Down){
        if (pos().y()+100 < 600){
        setPos(x(),y()+10);
        }
    }

    //shooting bullets
    else if (event->key() == Qt::Key_Space){
        //create a bullet object
        Bullet* bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);//add bullet to the scene

    }
}
