#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "Button.h"
#include <QImage>
#include <QBrush>

Game::Game(QWidget *parent){

    // create the scene
    scene = new QGraphicsScene(); //x goes downward (v) y goes rightward(>)
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
    setBackgroundBrush(QBrush(QImage(":/images/bg1.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setFixedSize(800,600);

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800,600);//fix the view size

    // create the player
     player = new Player();
     player->setPos(350,475);
     // make the player focusable and set it to be the current focus
     player->setFlag(QGraphicsItem::ItemIsFocusable);
     player->setFocus();
     // add the player to the scene
     scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    // create the health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);//enemy spawns every 2000 miliseconds
}

void Game::back(){
    scene->clear();
    displayMainMenu();
}

void Game::gameOver(){

    //disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }
       //scene->clear();

    QGraphicsTextItem* goText = new QGraphicsTextItem(QString("GAME OVER"));
    QFont goFont("comic sans",50);
    goText->setFont(goFont);
    int goxPos = this->width()/2 - goText->boundingRect().width()/2;
    int goyPos = 200;
    goText->setPos(goxPos,goyPos);
    scene->addItem(goText);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    int pgxPos = this->width()/2 - goText->boundingRect().width()/2 + 35;
    int pgyPos = 280;
    playAgain->setPos(pgxPos,pgyPos);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));

    // create Quit button
    Button* quit = new Button(QString("Quit"));
    int qxPos = this->width()/2 - goText->boundingRect().width()/2 + 35;
    int qyPos = 350;
    quit->setPos(qxPos,qyPos);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

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
    QString instructions = "        Use the arrow keys to control the Jet Fighter.\n                       Use the SpaceBar to shoot\n  Don't allow any enemies to go past you or else you lose health. \n         The game ends when your health reaches 0. \n";
    QGraphicsTextItem* instrText = new QGraphicsTextItem(instructions);
    QFont instrFont("comic sans",25);
    instrText->setFont(instrFont);
    int ixPos = this->width()/2 - instrText->boundingRect().width()/2;
    int iyPos = 250;
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

