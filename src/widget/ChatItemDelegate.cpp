#include "src/widget/ChatItemDelegate.h"
#include "src/entity/Message.h"

#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QPainterPath>

ChatItemDelegate::ChatItemDelegate(QWidget *parent) : QStyledItemDelegate(parent)
{

}

void ChatItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    painter->setRenderHint(QPainter::Antialiasing, true);

    message msg = index.model()->data(index, Qt::UserRole).value<message>();
    switch(msg.msg_type)
    {
    case MSG_SYSTEM:
        drawSys(painter, option);
        break;
    case MSG_SENT:
        break;
    case MSG_RECEIVED:
        break;
    }
}

QWidget *ChatItemDelegate::createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
{
    return NULL;
}

QSize ChatItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    return QSize(size.width(), 65);
}

void ChatItemDelegate::drawSys(QPainter *painter, const QStyleOptionViewItem &option) const
{

}
