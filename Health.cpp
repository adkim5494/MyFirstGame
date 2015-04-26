#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem* parent): QGraphicsTextItem(parent) {
    //initialize the score to 0
    health = 100;

    //draw the Health text
    setPlainText(QString("Health: ") + QString::number(health)); //Health: 100;
    setDefaultTextColor(Qt::green);
    setFont(QFont("Arial", 16)); //Font, Size

}

void Health::decrease_health() {
    health--;
    //re-draw the Health text
    setPlainText(QString("Health: ") + QString::number(health)); //Health: 99;
}



int Health::get_health() {
    return health;
}
