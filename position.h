#ifndef POSITION_H
#define POSITION_H

#include <QPoint>
#include <QSize>
#include <QPixmap>

class QPainter;

class Position
{
public:
    Position(QPoint pos, const QPixmap &sprite = QPixmap(":/flower_pot.gif"));

    void setHasTower(bool hasTower = true);
    bool hasTower() const;
    const QPoint centerPos() const;
    bool containPoint(const QPoint &pos) const;

    void draw(QPainter *painter) const;

private:
    bool		m_hasTower;
    QPoint		m_pos;
    QPixmap		m_sprite;

    static const QSize ms_fixedSize;
signals:

};

#endif // POSITION_H
