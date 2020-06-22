#include "plant.h"
#include"position.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>

const QSize Plant::ms_fixedSize(60,52);
Plant::Plant(QPoint pos, Window1 *game, const QPixmap &sprite)
    :
      m_attackRange(100)
    , m_damage(10)
    , m_fireRate(1000)
    , m_rotationSprite(0.0)
    , m_game(game)
    , m_pos(pos)
    , m_sprite(sprite)
{


}

void Plant:: draw(QPainter *painter) const{


        painter->save();
        //painter->setPen(Qt::black);
        // 绘制攻击范围
        //painter->drawEllipse(m_pos, m_attackRange, m_attackRange);

        // 绘制偏转坐标,由中心+偏移=左上
        static const QPoint offsetPoint(-ms_fixedSize.width()/3.5, -ms_fixedSize.height());
        // 绘制炮塔并选择炮塔
        painter->translate(m_pos);

        painter->drawPixmap(offsetPoint, m_sprite);
        painter->restore();

}
