#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include"mybutton.h"
#include"mywindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(900,800);
    ui->setupUi(this);

    MyButton *btn = new MyButton(":/button1.png");
    btn->setParent(this);
    btn->move(700,500);//按钮位置
    MyWindow *scene = new MyWindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        btn->down();
        btn->up();
        QTimer::singleShot(200,this,[=](){
            this->hide();
            scene->show();

        });

    });
    connect(scene,&MyWindow::chooseBack,this,[=](){
        scene->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/mainscreen.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
