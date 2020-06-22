#include "waypoint.h"
#include <QPainter>
#include <QColor>

WayPoint::WayPoint(QPoint pos)
    : m_pos(pos)
    , m_nextWayPoint(NULL)
{
}

//设置下一个路线节点
void WayPoint::setNextWayPoint(WayPoint *nextPoint)
{
    m_nextWayPoint = nextPoint;
}

//返回下一个路线节点
WayPoint* WayPoint::nextWayPoint() const
{
    return m_nextWayPoint;
}

//返回当前路线节点
const QPoint WayPoint::pos() const
{
    return m_pos;
}

//显示路线及各个路线节点
void WayPoint::draw(QPainter *painter) const
{
    painter->save();
    painter->setPen(QColor(255,228,181));//设置路线颜色

    painter->drawEllipse(m_pos, 2, 2);//路线中各节点标记点

    if (m_nextWayPoint)
        painter->drawLine(m_pos, m_nextWayPoint->m_pos);
    painter->restore();
}
