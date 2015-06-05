#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QSet>

/**
 * @class Player
 * @brief The Player class is responsible for creating the Player and also spawning the enemies.
 */
class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    /**
     * @brief keeps track the keys pressed for the player
     */
    void keyPressEvent(QKeyEvent* event);

    QSet<int> keysPressed;
public slots:
        void spawn();

};

#endif // PLAYER_H
