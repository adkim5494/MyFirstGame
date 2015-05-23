#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Button.h"
#include <QImage>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

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
    // clear the screen
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
}

void Game::back(){
    scene->clear();
    displayMainMenu();
}

void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("SUPER ULTIMATE JET FIGHTER"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int pxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 275;
    playButton->setPos(pxPos,pyPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    // create the instructions button
    Button* instrButton = new Button(QString("Instructions"));
    int ixPos = this->width()/2 - instrButton->boundingRect().width()/2;
    int iyPos = 425;
    instrButton->setPos(ixPos,iyPos);
    connect(instrButton,SIGNAL(clicked()),this,SLOT(instr()));
    scene->addItem(instrButton);

    show();
}

void Game::instr(){
    // clear the screen
    scene->clear();

    // create the instructions title
    QGraphicsTextItem* instrTitle = new QGraphicsTextItem(QString("SUPER ULTIMATE INSTRUCTIONS"));
    QFont instrTitleFont("comic sans",50);
    instrTitle->setFont(instrTitleFont);
    int txPos = this->width()/2 - instrTitle->boundingRect().width()/2;
    int tyPos = 25;
    instrTitle->setPos(txPos,tyPos);
    scene->addItem(instrTitle);

    // create the instructions text
    QString instructions = "Use the arrow keys to control the Jet Fighter. /n"
                           "Don't allow any enemies to go past you or else you lose health /n";
    QGraphicsTextItem* instrText = new QGraphicsTextItem(instructions);
    QFont instrFont("comic sans",25);
    instrText->setFont(instrFont);
    int ixPos = this->width()/2 - instrText->boundingRect().width()/2;
    int iyPos = 75;
    instrText->setPos(ixPos,iyPos);
    scene->addItem(instrText);

    // create the back button
    Button* backButton = new Button(QString("Back"));
    int bxPos = this->width()/2 - backButton->boundingRect().width()/2;
    int byPos = 525;
    backButton->setPos(bxPos,byPos);
    connect(backButton,SIGNAL(clicked()),this,SLOT(back()));
    scene->addItem(backButton);
    show();
}

