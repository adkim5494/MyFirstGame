#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QMouseEvent>

//Game View Item holds pointers to scene, score, and player
class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructors
    Game(QWidget* parent = NULL);

    //public methods
    void displayMainMenu();

    //public attributes
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health * health;

    //events
    void mousePressEvent(QMouseEvent *event);

public slots:
    void start();

};

#endif // GAME_H
