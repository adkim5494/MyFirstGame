#include "Player.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Enemy.h"

void Player::keyPressEvent(QKeyEvent *event){
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
        bullet->setPos(x()+22.5,y());
        scene()->addItem(bullet);//add bullet to the scene

    }
}

void Player::spawn(){
    //create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);//adds enemy object to the scene of the player object
}
