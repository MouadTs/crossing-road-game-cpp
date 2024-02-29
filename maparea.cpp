#include "maparea.h"

MapArea::MapArea(const QString& imagePath,int y, int height) {
    QPixmap originalPixmap(imagePath);
    int pwidth = 800;
    int pheight = height;

    QPixmap scaledPixmap = originalPixmap.scaled(pwidth, pheight);

    setPixmap(scaledPixmap);

    setPos(0, y);
    setZValue(-2);
}
