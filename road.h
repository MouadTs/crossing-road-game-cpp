#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QList>

class Car;  // Forward declaration

class Road : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Road(int y,int speed,int height);


private slots:
    void moveCars();
    void addCar();

private:
    QList<Car *> cars;
    int carspeed;
    int carpos;

};

#endif // ROAD_H
