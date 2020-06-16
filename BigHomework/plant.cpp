#include "plant.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include<QMovie>

Plant::Plant(QPoint pos,QString pixFileName) : QObject(0),pixmap(pixFileName)
{

    _pos=pos;

}
void Plant:: draw(QPainter *painter){
    painter->drawPixmap(_pos,pixmap);

}
