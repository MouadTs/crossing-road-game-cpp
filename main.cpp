#include <QApplication>
#include "game.h"



/* using  :
QGraphicsScene
QGraphicsItem
QGraphiqueView
*/
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();



    return a.exec();
}
