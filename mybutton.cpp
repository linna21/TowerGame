#include "mybutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

MyButton::MyButton(QString pix) : QPushButton(0)
{
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());//设置按钮大小
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);//传入图片
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));//图片大小和按钮大小保持一致


}

void MyButton::down(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));//起始位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));//终止位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//曲线
    animation->start();//执行
}
void MyButton::up(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
