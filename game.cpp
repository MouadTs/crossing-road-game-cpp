#include "game.h"
#include <QApplication>





Game::Game() {
    // create a scene
    scene = new QGraphicsScene();

    // create the player
    person = new player();


    // create a score
    score = new Score();
    scene->addItem(score);

    // add the player to the scene
    scene->addItem(person);
    // create a road
    road1 = new Road(-70,8,170);//3
    road2 = new Road(100,40,180);//2
    road3 = new Road(350,50,180);// first road
    road4 = new Road(-400,8,200); //4
    road5 = new Road(-550,8,170);//5
    road6 = new Road(-800,10,250);//6
    road7 = new Road(-1200,8,150);//7
    road8 = new Road(-2100,10,300);
    /// map decoration

    map1 = new MapArea(":/F:/ressources/map.jpg",400,250);
    map2 = new MapArea(":/F:/ressources/map.jpg",-200,250);
    map3 = new MapArea(":/F:/ressources/map.jpg",-1050,250);
    map4 = new MapArea(":/F:/ressources/map22.jpg",-1800,600);
    map5 = new MapArea (":/F:/ressources/map22.jpg",-2700,600);
    map6 = new MapArea (":/F:/ressources/map.jpg",200,250);







    scene->addItem(road1);
    scene->addItem(road2);
    scene->addItem(road3);
    scene->addItem(road4);
    scene->addItem(road5);
    scene->addItem(road6);
    scene->addItem(road7);
    scene->addItem(road8);
    // add map areas
    scene->addItem(map1);
    scene->addItem(map2);
    scene->addItem(map3);
    scene->addItem(map4);
    scene->addItem(map5);
    scene->addItem(map6);




    //make item focusable  and focus it
    person->setFlag(QGraphicsItem::ItemIsFocusable);
    person->setFocus();

    // create a view : so the scene can be showed
    view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    view->centerOn(person);
    view->setFixedSize(800,700);
    scene->setSceneRect(0,0,800,600);
    person->setPos(view->width()/2,view->height() - person->pixmap().height()-20);


    // play background music

}

void Game::show(){
    view->show();
}



Score *Game::getscore() const
{
    return score;
}

QGraphicsView *Game::getview() const
{
    return view;
}



