#include "mainwindow.h"
#include <QApplication>

#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    //create an item to put into the scene
    MyRect* player = new MyRect();
    player->setRect(0,0,100,100);

    //add the item to the scene
    scene->addItem(player);

    //make personal player item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();//player is focused item which gets keyboard events

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view ->show();
    view->setFixedSize(800,600);//fix the view size
    scene->setSceneRect(0,0,800,600);//want the scene to be same size as view

    player->setPos(view->width()/2-50,view->height() - player->rect().height());

    return a.exec();
}
