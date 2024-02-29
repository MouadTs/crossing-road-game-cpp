#ifndef MAPAREA_H
#define MAPAREA_H

#include <QGraphicsPixmapItem>

class MapArea : public QGraphicsPixmapItem {
public:
    MapArea(const QString& imagePath,int y,int height);

private:
         // You can add any private members if needed
};

#endif // MAPAREA_H
