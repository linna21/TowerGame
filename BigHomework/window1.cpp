#include "mywindow.h"
#include "mybutton.h"
#include "window1.h"
#include "position.h"


#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QLabel>


Window1::Window1(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
//返回按钮
    MyButton * rbtn=new MyButton(":/returnbtn.png");
    rbtn->setParent(this);
    rbtn->move(50,50);
    connect(rbtn,&QPushButton::clicked,this,[=](){
        rbtn->down();
        rbtn->up();
    });

    connect(rbtn,&MyButton::clicked,this,[=](){
        QTimer::singleShot(200,this,[=](){
            emit chooseBack(); //发送返回信号
        });
    });
 //种花盆

    loadTowerPositions();





}


void Window1::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pixmap(":/background1.png");

    QPainter cachePainter(&pixmap);
    foreach (const Position &Pos, m_towerPositionsList)
        Pos.draw(&cachePainter);
    QPainter painter1(this);
    painter1.drawPixmap(0, 0, this->width(),this->height(),pixmap);
}

void Window1::loadTowerPositions(){

 QPoint pos[] =
 {
  QPoint(300, 200),
  QPoint(300, 400),
  QPoint(300, 300),
  QPoint(300, 500),


  QPoint(370, 110),
  QPoint(600, 200),
  QPoint(530, 200),
  QPoint(760, 200),
  QPoint(760, 300),
  QPoint(760, 400),
  QPoint(760, 500),
  QPoint(760, 100),

  QPoint(670, 500),

  QPoint(840, 500),
  QPoint(840, 400),
  QPoint(840, 300),

 };
 int len = sizeof(pos) / sizeof(pos[0]);

 for (int i = 0; i < len; ++i)
  m_towerPositionsList.push_back(pos[i]);
}



