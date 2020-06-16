#include "mywindow.h"
#include "mybutton.h"
#include "window1.h"
#include "window2.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(900,800);
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

    Window1 *scene1 = new Window1;
    Window2 *scene2 = new Window2;

    connect(scene1,&Window1::chooseBack,this,[=](){
        scene1->hide();
        this->show();
    });
    connect(scene2,&Window2::chooseBack,this,[=](){
        scene2->hide();
        this->show();
    });

 //场景1
    MyButton * cbtn1=new MyButton(":/choose1.png");
    cbtn1->setParent(this);
    cbtn1->move(150,300);
    connect(cbtn1,&QPushButton::clicked,this,[=](){
        cbtn1->down();
        cbtn1->up();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            scene1->show();

        });
    });

//场景2

    MyButton * cbtn2=new MyButton(":/choose2.png");
    cbtn2->setParent(this);
    cbtn2->move(575,300);
    connect(cbtn2,&QPushButton::clicked,this,[=](){
        cbtn2->down();
        cbtn2->up();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            scene2->show();

        });

    });
//设置标题
    title->setText("Choose   a   scene!");
    title->setGeometry(360, 15, 240, 100);
    title->setFont(QFont("Consolas", 20));
    title->show();



}



void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/choose.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);

}
