#ifndef CHATLISTITEMDELEGATE_H
#define CHATLISTITEMDELEGATE_H

#include <QStyledItemDelegate>

class ChatListItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChatListItemDelegate(QObject *parent = 0);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CHATLISTITEMDELEGATE_H
