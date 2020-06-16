#ifndef PLANT_H
#define PLANT_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include <QMovie>
class Plant : public QObject
{
    Q_OBJECT
public:
    Plant(QPoint pos,QString pixFileName);
    void draw(QPainter *painter);


private:

    QPoint _pos;
    QPixmap pixmap;


signals:

};

#endif // PLANT_H
