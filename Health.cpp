#include "Health.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include "Game.h"

Health::Health(QGraphicsItem* parent): QGraphicsRectItem(parent) {
    //initialize the score to 0
    health = 100;

    setRect(0,0,100,30);
    setBrush(QBrush(Qt::red));

}

void Health::decrease_health() {

    health-=5;

    double fill = double(health) / 100;
    setRect(rect().x(),rect().y(),fill * 100,30);

    if (health <= 0){
        game->gameOver();
    }

}

int Health::get_health() {
    return health;
}
