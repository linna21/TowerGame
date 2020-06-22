#include "mywindow.h"
#include "mybutton.h"
#include "window2.h"


#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QLabel>


Window2::Window2(QWidget *parent) : QMainWindow(parent)
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
 //种植物

}


void Window2::paintEvent(QPaintEvent *){

    QPainter painter(this);
    QPixmap pixmap(":/background2.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);


//画植物


}

