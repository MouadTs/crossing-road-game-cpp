#include "Road.h"
#include "vehicule.h"
#include <QTimer>
#include <cstdlib>
#include <QList>

Road::Road(int ypos, int speed,int height) : carspeed(speed), carpos(ypos)
{
    QPixmap originalPixmap(":/F:/ressources/road.png");
    int pwidth = 800;
    int pheight = height;

    QPixmap scaledPixmap = originalPixmap.scaled(pwidth, pheight);

    setPixmap(scaledPixmap);
    setPos(0, ypos);
    setZValue(-1);

    // Timer for adding cars every second
    QTimer *addCarTimer = new QTimer(this);
    connect(addCarTimer, &QTimer::timeout, this, &Road::addCar);
    addCarTimer->start(1500); // Set the timer interval to 2500 milliseconds (2.5 seconds)

    // Timer for moving cars
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Road::moveCars);
    timer->start(40); // Adjust the timer interval as needed
}

void Road::addCar()
{
    QStringList carImagePaths={
        ":/F:/ressources/Untitled design.png",
        ":/F:/ressources/2.png",
        ":/F:/ressources/3.png",
        ":/F:/ressources/4.png",
        ":/F:/ressources/5.png"
    };

    // Randomly select an image path for the new car
    QString randomImagePath = carImagePaths.at(std::rand() % carImagePaths.size());

    Car *car = new Car(scene(), randomImagePath); // Pass the image path to the Car constructor
    car->setPos(-car->pixmap().width(), std::rand() % 100 + carpos);
    car->setSpeed(carspeed);
    cars.append(car);
}

void Road::moveCars()
{
    for (Car *car : cars)
    {
        car->move();
        if (car->y() > scene()->height())
        {
            scene()->removeItem(car);
            cars.removeOne(car);
            delete car;
        }
    }
}
