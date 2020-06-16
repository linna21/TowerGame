#ifndef WINDOW2_H
#define WINDOW2_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QList>
#include "plant.h"


class Window2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//重绘事件处理函数的声明
    void set_plant();
private:
    QList<Plant*>plant_list;

signals:
     void chooseBack();

};

#endif // WINDOW2_H
