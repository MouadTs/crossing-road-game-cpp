#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class player : public QGraphicsPixmapItem {
public:
    player();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void setPlayerImage(const QString& imagePath);
    void endGame();
    int distanceCounter;
};

#endif // PLAYER_H
