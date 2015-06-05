#include <QApplication>
#include "Game.h"

Game * game; //make game object global

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->displayMainMenu();

    return a.exec();
}

//http://www.freebackgroundremoval.com/
//background provided by davis123
//space ships http://opengameart.org/users/skorpio
//bg music provided by FoxSynergy
