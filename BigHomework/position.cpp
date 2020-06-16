#include "position.h"
#include <QPainter>

const QSize Position::ms_fixedSize(800, 600);

Position::Position(QPoint pos, const QPixmap &sprite)
    : m_hasTower(false)
    , m_pos(pos)
    , m_sprite(sprite)
{
}

//找到塔坑中心点
const QPoint Position::centerPos() const
{
    QPoint offsetPoint(ms_fixedSize.width() / 2, ms_fixedSize.height() / 2);
    return m_pos + offsetPoint;
}

bool Position::containPoint(const QPoint &pos) const
{
    bool isXInHere = m_pos.x() < pos.x() && pos.x() < (m_pos.x() + ms_fixedSize.width());
    bool isYInHere = m_pos.y() < pos.y() && pos.y() < (m_pos.y() + ms_fixedSize.height());
    return isXInHere && isYInHere;
}

bool Position::hasTower() const
{
    return m_hasTower;
}

void Position::setHasTower(bool hasTower)
{
    m_hasTower = hasTower;
}

void Position::draw(QPainter *painter) const
{
    painter->drawPixmap(m_pos.x(), m_pos.y(), m_sprite);
}
