#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QLabel>

class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//重绘事件处理函数的声明:
    QLabel* title = new QLabel(this);

signals:
    void chooseBack();




};

#endif // MYWINDOW_H
