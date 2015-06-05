#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

/**
@mainpage SUPER ULTIMATE JET FIGHTER
@author Andrew Kim
@version 1.0
@brief SUPER ULTIMATE JET FIGHTER is an arcade style game loosely based off of the classic Space Invaders.
@section Controls
-move with the Arrow Keys \n
-use the spacebar to shoot \n
@section Gameplay Summary
You start in a terrain and cannot let the enemies pass you. Or else, your health will go down.\n
The game ends when your health bar reaches 0.
*/

/**
 *@class Game
 *@brief The Game class represents an instance of game.
 *
 * The Game class is the parent of all the elements of the game (i.e. bullets, player, enemies, etc.)
 * It is responsible for deallocating all the heap memory
 */

class Game;
extern Game* game;

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game(QWidget* parent = NULL);

    //public methods
    void displayMainMenu();
    void gameOver();

    //public attributes
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

public slots:
    void start();
    void instr();// instructions
    void back();// goes back to main menu
};

#endif // GAME_H
