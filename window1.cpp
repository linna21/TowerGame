#include "mywindow.h"
#include "mybutton.h"
#include "window1.h"
#include "position.h"
#include "plant.h"
#include "waypoint.h"
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QLabel>


Window1::Window1(QWidget *parent)
  : QMainWindow(parent)
  , m_playerHp(5)
  , m_playrGold(1000)
  , m_waves(0)
  , m_gameWin(false)
  , m_gameEnded(false)

{
     this->setFixedSize(1024,1024);
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
    //路线
    addWayPoints();
    //关联一个QTimer，每30ms发送一个信号，更新一次map，主要是为了移动敌人，模拟帧数
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateMap()));
    timer->start(30);
    // 设置300ms后游戏启动
    QTimer::singleShot(300, this, SLOT(gameStart()));


}


void Window1::paintEvent(QPaintEvent *){


    QPixmap pixmap(":/background1.png");
    //画花盆
    QPainter cachePainter(&pixmap);
    foreach (const Position &Pos, m_towerPositionsList)
        Pos.draw(&cachePainter);

    //画植物
    foreach(const Plant *plant,m_towerslist)
        plant->draw(&cachePainter);
    //画路线
    foreach (const WayPoint *wayPoint, m_wayPointsList)
        wayPoint->draw(&cachePainter);
    //画僵尸
    foreach (const Enemy *enemy, m_enemyList)
        enemy->draw(&cachePainter);

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(),this->height(),pixmap);
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

  QPoint(680, 500),
  QPoint(840, 300),
  QPoint(840, 500),
  QPoint(840, 400),


 };
 int len = sizeof(pos) / sizeof(pos[0]);

 for (int i = 0; i < len; ++i)
  m_towerPositionsList.push_back(pos[i]);
}
//里用鼠标点击放置塔
void Window1::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    auto it = m_towerPositionsList.begin();
    while (it != m_towerPositionsList.end())
    {

        if (canBuyTower() && it->containPoint(pressPos)&& !it->hasTower() )
        //可以买塔 && 点击部位是有效部位 && 此处没有塔
        {
            it->setHasTower();
            Plant *plant = new Plant(it->centerPos(), this);
            m_towerslist.push_back(plant);
            update();
            break;
        }


        ++it;
    }
}

//确认是否有足够金币购买塔
bool Window1::canBuyTower() const
{

        return true;

}

//设置路线节点
void Window1::addWayPoints()
{
    WayPoint *wayPoint1 = new WayPoint(QPoint(410, 580));
    m_wayPointsList.push_back(wayPoint1);

    WayPoint *wayPoint2 = new WayPoint(QPoint(410, 230));
    m_wayPointsList.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3 = new WayPoint(QPoint(485, 230));
    m_wayPointsList.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4 = new WayPoint(QPoint(485, 110));
    m_wayPointsList.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5 = new WayPoint(QPoint(715, 110));
    m_wayPointsList.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6 = new WayPoint(QPoint(715, 400));
    m_wayPointsList.push_back(wayPoint6);
    wayPoint6->setNextWayPoint(wayPoint5);

    WayPoint *wayPoint7 = new WayPoint(QPoint(640,400));
    m_wayPointsList.push_back(wayPoint7);
    wayPoint7->setNextWayPoint(wayPoint6);

    WayPoint *wayPoint8 = new WayPoint(QPoint(640,620));
    m_wayPointsList.push_back(wayPoint8);
    wayPoint8->setNextWayPoint(wayPoint7);

    WayPoint *wayPoint9 = new WayPoint(QPoint(950,620));
    m_wayPointsList.push_back(wayPoint9);
    wayPoint9->setNextWayPoint(wayPoint8);

    WayPoint *wayPoint10 = new WayPoint(QPoint(950,285));
    m_wayPointsList.push_back(wayPoint10);
    wayPoint10->setNextWayPoint(wayPoint9);
}
//敌人进入终点，玩家HP减少
void Window1::getHpDamage(int damage)
{


}

//敌人的死亡清除及波数的递增
void Window1::removedEnemy(Enemy *enemy)
{
    m_enemyList.removeOne(enemy);
    delete enemy;

    if (m_enemyList.empty())
    {
        ++m_waves;
        if (!loadWave())
        {   // 当没有下一波时，这里表示游戏胜利
            // 设置游戏胜利标志为true
            m_gameWin = true;
            // 游戏胜利转到游戏胜利场景
            // 这里暂时以打印处理
        }
    }
}
bool Window1::loadWave()
{
    if (m_waves >= 6)
        return false;
    WayPoint *startWayPoint = m_wayPointsList.back(); // 这里是个逆序的，尾部才是其实节点
    int enemyStartInterval[] = { 500, 5000, 7000, 9000, 10000, 000 };
    for (int i = 0; i < 6; ++i)
    {
        Enemy *enemy = new Enemy(startWayPoint, this);
        m_enemyList.push_back(enemy);
        QTimer::singleShot(enemyStartInterval[i], enemy, SLOT(doActivate()));
    }
    return true;
}
void Window1::updateMap()
{
    foreach (Enemy *enemy, m_enemyList)
        enemy->move();
    update();
}
//开始游戏
void Window1::gameStart()
{
    loadWave();
}

