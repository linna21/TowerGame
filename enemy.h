#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>
#include <QColor>

class WayPoint;
class QPainter;
class Window1;
class Plant;

class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint, Window1 *game, const QPixmap &sprite = QPixmap(":/enemy.gif"));


    void draw(QPainter *painter) const;
    void move();
    QPoint pos() const;

public slots:
    void doActivate();

private:
    bool			m_active;//判断是否可以移动
    int				m_maxHp;
    int				m_currentHp;
    qreal			m_walkingSpeed;
    qreal			m_rotationSprite;

    QPoint			m_pos;
    WayPoint *		m_destinationWayPoint;//储存当前航点
    Window1 *	    m_game;
    QList<Plant *>	m_attackedTowersList;

    const QPixmap	m_sprite;
    static const QSize ms_fixedSize;
};

#endif // ENEMY_H
