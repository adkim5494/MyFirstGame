#include <QApplication>
#include "Game.h"

Game * game; //make game object global

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
