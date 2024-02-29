#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Car : public QGraphicsPixmapItem {
public:
    Car(QGraphicsScene *scene,const QPixmap &carPixmap);
    void move();
    void setSpeed(int s);
    int getspeed();

private:
    int speed;  // Default speed
};

#endif // CAR_H
