#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QString pix);
    void down();
    void up();
    bool cli=false;//有没有点击


signals:

};

#endif // MYBUTTON_H
