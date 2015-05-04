#include "Game.h"
#include "Enemy.h"
#include "Button.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>


Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setFixedSize(800,600);

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800,600);//fix the view size
}

void Game::start(){
    //clear the screen
    scene->clear();

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setFixedSize(800,600);

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800,600);//fix the view size

    // create the player
    player  = new Player();
    player->setRect(0,0,100,100); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(view->width()/2-50,view->height() - player->rect().height());
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);//enemy spawns every 2000 miliseconds

    show();
}

void Game::displayMainMenu() {
    //create the Title
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("SUPER MEGA ULTIMATE FIGHTER JET"));
    QFont titleFont("Arial", 50);
    titleText->setFont(titleFont);

    //set positions
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos, tyPos);
    scene->addItem(titleText);

    //create play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}
