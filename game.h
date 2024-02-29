#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include "player.h"
#include "road.h"
#include "score.h"
#include "maparea.h"




class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    void displaymenu();
    Score *getscore() const;
    QGraphicsView * getview()const;

public slots:
    void show();
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    player *person;
    Road *road1;
    Road *road2;
    Road *road3;
    Road *road4;
    Road *road5;
    Road *road6;
    Road *road7;
    Road *road8;
    // player score
    Score *score;
    // map decoration
    MapArea *map1;
    MapArea *map2;
    MapArea *map3;
    MapArea *map4;
    MapArea *map5;
    MapArea *map6;


};

#endif // GAME_H
