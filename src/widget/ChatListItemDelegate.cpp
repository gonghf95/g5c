#include "src/widget/ChatListItemDelegate.h"

#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QPainterPath>

ChatListItemDelegate::ChatListItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ChatListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(!index.isValid())
        return;

    QString text = index.model()->data(index, Qt::DisplayRole).toString();
    QString now = QTime::currentTime().toString("hh:mm");

    painter->setRenderHint(QPainter::Antialiasing, true);

    if(QStyle::State_Selected & option.state)
    {
        painter->fillRect(option.rect, QColor(198, 198, 198));
    }
    else if(QStyle::State_MouseOver & option.state)
    {
        painter->fillRect(option.rect, QColor(215, 216, 217));
    }

    const QRect rect = option.rect;

    QPen pen;
    pen.setColor(QColor(153, 153, 153));
    painter->setPen(pen);

    // thumbnail
    QRect thumbnail(QPoint(rect.x() + 10, rect.y() + 12), QSize(40, 40));
    painter->drawRect(thumbnail);

    painter->save();

    pen.setColor(QColor(0, 0, 0));
    painter->setPen(pen);

    // name
    QRect name(QPoint(rect.x() + 60, rect.y() + 12), QSize(140, 18));
    painter->drawText(name, text);

    painter->restore();

    // time
    QRect time(QPoint(rect.x() + 200, rect.y() + 12), QSize(40, 18));
    painter->drawText(time, now);

    // content
    QRect content(QPoint(rect.x() + 60, rect.y() + 36), QSize(140, 20));
    painter->drawText(content, "[image]xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
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
