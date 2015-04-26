#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

//signals and slots must be derived from QObjects and add the Q_OBJECT macro
class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
};

#endif // ENEMY_H
