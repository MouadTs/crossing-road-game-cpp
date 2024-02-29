#include "score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent): QGraphicsTextItem (parent)
{
    // initialize the score to 0
    score=0;

    // draw the text
    setPlainText(QString("Score: ")+QString::number(score)); // score = 0
    setDefaultTextColor(Qt::red);
    setFont(QFont("Impact", 18));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getscore()
{
    return score;
}

void Score::reset()
{
    score=0;
}
