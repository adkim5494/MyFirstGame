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
    MyRect* rect = new MyRect();
    rect->setRect(0,0,100,100);

    //add the item to the scene
    scene->addItem(rect);

    //make personal rect item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();//rect is focused item which gets keyboard events

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view ->show();
    return a.exec();

}
