#include "src/widget/ChatItemDelegate.h"
#include "src/entity/Message.h"

#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QFontMetrics>

ChatItemDelegate::ChatItemDelegate(QWidget *parent) : QStyledItemDelegate(parent)
{

}

void ChatItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    painter->setRenderHint(QPainter::Antialiasing, true);

    ChatMsg msg = index.model()->data(index, Qt::UserRole).value<ChatMsg>();
    switch(msg.msg_type)
    {
    case MSG_SYSTEM:
        drawSystemMessage(painter, option, msg);
        break;
    case MSG_SENT:
        break;
    case MSG_RECEIVED:
        drawReceivedMessage(painter, option, msg);
        break;
    }
}

QWidget *ChatItemDelegate::createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
{
    return NULL;
}

QSize ChatItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return QSize();
    }

    QSize size = QStyledItemDelegate::sizeHint(option, index);
    ChatMsg msg = index.model()->data(index, Qt::UserRole).value<ChatMsg>();
    if(MSG_SYSTEM == msg.msg_type)
    {
        return QSize(size.width(), size.height() + 2);
    }

    QFont font = option.font;
    QRect rect = option.rect;
    QFontMetrics fm(font);
    QRect fontRect = fm.boundingRect(rect, Qt::AlignTop|Qt::AlignLeft|Qt::TextWordWrap, msg.text);

    const int width = rect.width();
    int height = fontRect.height();
    if(height < 45)
        height = 25;

    return QSize(width, height+20);
}

void ChatItemDelegate::drawSystemMessage(QPainter *painter, const QStyleOptionViewItem &option, const ChatMsg &msg) const
{
    const QRect rect = option.rect;
    const QFontMetrics fm(painter->font());
    const QRect fontRect = fm.boundingRect(msg.text);
    const int fontWidth = fm.horizontalAdvance(msg.text);

    const QRect textRect(QPoint(rect.x()+(rect.width()-fontWidth)/2+2, rect.y()),
                             QSize(fontWidth+1, fontRect.height()));

    const QRect textBackgroundRect(QPoint(rect.x()+(rect.width()-fontWidth)/2, rect.y()),
                                   QSize(fontWidth+4, rect.height()));


    painter->save();

    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(Qt::gray));
    painter->drawRoundedRect(textBackgroundRect, 4, 4);

    painter->restore();

    painter->setPen(Qt::white);
    painter->drawText(textRect, msg.text);
}

void ChatItemDelegate::drawReceivedMessage(QPainter *painter, const QStyleOptionViewItem &option, const ChatMsg &msg) const
{
    const QRect rect = option.rect;
    const QFontMetrics fm(painter->font());
    const QRect fontRect = fm.boundingRect(QRect(rect.x(), rect.y(), rect.width()*0.6, rect.height()), Qt::AlignTop|Qt::AlignLeft|Qt::TextWordWrap, msg.text);

    painter->setPen(Qt::black);

    // avatarRect
    QRect avatarRect(QPoint(rect.x()+12, rect.y()), QSize(40, 40));
    painter->drawRect(avatarRect);

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(Qt::white));

    // rectangle
    QPoint points[3] = {
        QPoint(avatarRect.right()+5, avatarRect.y()+avatarRect.height()/2+8),
        QPoint(avatarRect.right()+5+5, avatarRect.y()+avatarRect.height()/2+8-4),
        QPoint(avatarRect.right()+5+5, avatarRect.y()+avatarRect.height()/2+8+4),
    };
    painter->drawPolygon(points, 3);

    // textRect
    QRect textBgRect(QPoint(points[1].x(), avatarRect.y()+18), QSize(fontRect.width() + 8, fontRect.height()));
    painter->drawRoundedRect(textBgRect, 4, 4);

    painter->restore();

    QRect textRect(QPoint(points[1].x()+4, avatarRect.y()+18+6), QSize(fontRect.width(), fontRect.height()));
    painter->drawText(textRect, Qt::TextWordWrap, msg.text);

    painter->setPen(Qt::red);
    painter->drawRect(fontRect);
    painter->drawRect(rect);
}
