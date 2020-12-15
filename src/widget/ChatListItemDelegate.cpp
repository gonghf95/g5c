#include "ChatListItemDelegate.h"

#include <QDebug>
#include <QPainter>

ChatListItemDelegate::ChatListItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ChatListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    QString text = index.model()->data(index, Qt::DisplayRole).toString();

    if(QStyle::State_Selected & option.state)
    {
        painter->fillRect(option.rect, QColor(235, 237, 240));
    }
    else if(QStyle::State_MouseOver & option.state)
    {
        painter->fillRect(option.rect, QColor(245, 246, 247));
    }

    const QRect rect = option.rect;

    // thumbnail
    QRect thumbnail(QPoint(rect.x() + 10, rect.y() + 12), QSize(40, 40));
    painter->drawRect(thumbnail);

    // name
    QRect name(QPoint(rect.x() + 55, rect.y() + 12), QSize(60, 18));
    painter->drawText(name, text);
}

QWidget *ChatListItemDelegate::createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
{
    return NULL;
}

QSize ChatListItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    return QSize(size.width(), 65);
}
