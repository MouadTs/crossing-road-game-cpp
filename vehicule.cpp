#include "vehicule.h"


Car::Car(QGraphicsScene *scene,const QPixmap &carPixmap)
{
    QPixmap scaledPixmap = carPixmap.scaled(150, 100); // Adjust the size as needed


    setPixmap(scaledPixmap);
    setZValue(1);

    if (scene)
    {
        scene->addItem(this);
    }
}

void Car::move() {
    setPos(x() + speed, y());
}

void Car::setSpeed(int s) {
    speed = s;
}

