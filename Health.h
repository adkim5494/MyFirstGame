#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsRectItem>

class Health: public QGraphicsRectItem {

public:
    Health(QGraphicsItem* parent = 0);
    void decrease_health();
    //void increase_health();
    int get_health();

private:
    int health;
};

#endif // HEALTH_H
