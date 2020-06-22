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
#include "waypoint.h"
#include "enemy.h"




class Window1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//重绘事件处理函数的声明
    void mousePressEvent(QMouseEvent *);
    void getHpDamage(int damage = 1);
    void removedEnemy(Enemy *enemy);
    void doGameOver();

private slots:
    void updateMap();
    void gameStart();


private:
    QList<Plant*>          m_towerslist;
    QList<Position>        m_towerPositionsList;
    void                   loadTowerPositions();
    bool                   canBuyTower() const;
    QList<WayPoint *>	   m_wayPointsList;
    void addWayPoints();
    QList<Enemy *>			m_enemyList;//敌人列表
    int		                m_playerHp;//玩家血量
    int		                m_playrGold;//玩家金币数
    int		                m_waves;//当前波数
    bool                    loadWave();//加载下一波敌人的数目和出现时间
    bool	                m_gameWin;
    bool	                m_gameEnded;
    QList<QVariant>			m_wavesInfo;//最大波数





signals:
     void chooseBack();

};

#endif // WINDOW1_H
