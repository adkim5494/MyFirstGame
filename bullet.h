#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

//signals and slots must be derived from QObjects and add teh Q_OBJECT macro
class Bullet: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
};

#endif // BULLET_H
