#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

//Game View Item holds pointers to scene, score, and player
class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game(QWidget* parent = NULL);

    //public methods
    void displayMainMenu();

    //public attributes
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

public slots:
    void start();
    void instr();//instructions
    void back();//goes back to main menu
};

#endif // GAME_H
