#ifndef PLANT_H
#define PLANT_H

#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QObject>
#include<QPainter>

class QPainter;

class Window1;
class QTimer;

class Plant : QObject
{
    Q_OBJECT
public:
    Plant(QPoint pos, Window1 *game, const QPixmap &sprite = QPixmap(":/Peashooter.gif"));

    void draw(QPainter *painter) const;



private slots:


private:
    int				m_attackRange;	// 代表塔可以攻击到敌人的距离
    int				m_damage;		// 代表攻击敌人时造成的伤害
    int				m_fireRate;		// 代表再次攻击敌人的时间间隔
    qreal			m_rotationSprite;
    Window1 *	    m_game;

    const QPoint	m_pos;
    const QPixmap	m_sprite;

    static const QSize ms_fixedSize;
};


#endif // PLANT_H
