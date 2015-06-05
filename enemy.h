#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**
 * @class Enemy
 * @brief The Enemy class is the enemey for the player. When the enemy passes the player
 * the player loses health.
 */

//signals and slots must be derived from QObjects and add the Q_OBJECT macro
class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
};

#endif // ENEMY_H
