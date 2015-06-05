#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/**
 * @class Bullet
 * @brief The Bullet class is the weapon which the player uses to defeat the enemies.
 */

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Bullet(QGraphicsItem * parent = NULL);

public slots:
    /**
     * @brief projects the player's bullet forward
     */
    void move();

};

#endif // BULLET_H
