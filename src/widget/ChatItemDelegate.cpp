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
        drawSentMessage(painter, option, msg);
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
    if(height < 35)
        height = 35;

    return QSize(width, height+32);
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
                                   QSize(fontWidth+4, fontRect.height()));


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
    QRect avatarRect(QPoint(rect.x()+12, rect.y()), QSize(35, 35));
    painter->drawRect(avatarRect);

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(Qt::white));

    // rectangle
    QPoint points[3] = {
        QPoint(avatarRect.right()+5, avatarRect.y()+avatarRect.height()/2+10),
        QPoint(avatarRect.right()+5+6, avatarRect.y()+avatarRect.height()/2+10-6),
        QPoint(avatarRect.right()+5+6, avatarRect.y()+avatarRect.height()/2+10+6),
    };
    painter->drawPolygon(points, 3);

    QRect textBackgroundRect(QPoint(points[1].x(), avatarRect.y()+12),
            QSize(fontRect.width() + 12, fontRect.height()+12));
    painter->drawRoundedRect(textBackgroundRect, 4, 4);

    painter->restore();

    // textRect
    QRect textRect(QPoint(textBackgroundRect.x()+6, textBackgroundRect.y()+6),
            QSize(fontRect.width(), fontRect.height()));
    painter->drawText(textRect, Qt::TextWordWrap, msg.text);
}

void ChatItemDelegate::drawSentMessage(QPainter *painter, const QStyleOptionViewItem &option, const ChatMsg &msg) const
{
    const QRect rect = option.rect;
    const QFontMetrics fm(painter->font());
    const QRect fontRect = fm.boundingRect(QRect(rect.x(), rect.y(), rect.width()*0.6, rect.height()), Qt::AlignTop|Qt::AlignLeft|Qt::TextWordWrap, msg.text);

    painter->setPen(Qt::black);

    // avatarRect
    QRect avatarRect(QPoint(rect.x()+rect.width()-52, rect.y()), QSize(35, 35));
    painter->drawRect(avatarRect);

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor("#9eea6e")));

    // rectangle
    QPoint points[3] = {
        QPoint(avatarRect.left()-5, avatarRect.y()+avatarRect.height()/2),
        QPoint(avatarRect.left()-5-6, avatarRect.y()+avatarRect.height()/2-6),
        QPoint(avatarRect.left()-5-6, avatarRect.y()+avatarRect.height()/2+6),
    };
    painter->drawPolygon(points, 3);

    QRect textBackgroundRect(QPoint(points[1].x() - fontRect.width() - 12, avatarRect.y()),
            QSize(fontRect.width() + 12, fontRect.height()+12));
    painter->drawRoundedRect(textBackgroundRect, 4, 4);

    painter->restore();

    // textRect
    QRect textRect(QPoint(textBackgroundRect.x()+6, textBackgroundRect.y()+6),
            QSize(fontRect.width(), fontRect.height()));
    painter->drawText(textRect, Qt::TextWordWrap, msg.text);
}
