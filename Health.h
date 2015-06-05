#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsRectItem>

/**
 * @class Health
 * @brief The Health classes displays the health of the player and updates according to the damage the player receives
 */

class Health: public QGraphicsRectItem {

public:
    Health(QGraphicsItem* parent = 0);

    /**
     * @brief decreases the health of the player
     */
    void decrease_health();

    /**
     * @brief yields the health of the player
     * @return returns the int of the health
     */
    int get_health();

private:
    int health;
};

#endif // HEALTH_H
