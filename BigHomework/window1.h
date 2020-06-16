#ifndef WINDOW1_H
#define WINDOW1_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QMovie>
#include "plant.h"
#include "position.h"




class Window1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//重绘事件处理函数的声明

private:
    QList<Plant*>plant_list;
    QList<Position> m_towerPositionsList;
    void loadTowerPositions();

signals:
     void chooseBack();

};

#endif // WINDOW1_H
