#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent) {
    //initialize the score to 0
    score = 0;

    //draw the Score text
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0;
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Arial", 16)); //Font, Size

}

void Score::increase_score() {
    score++;
    //draw the Score text
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 1;
}



int Score::get_score() {
    return score;
}
