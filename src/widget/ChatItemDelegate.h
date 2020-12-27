#ifndef WIDGET_CHATITEMDELEGATE_H
#define WIDGET_CHATITEMDELEGATE_H

#include <QStyledItemDelegate>

class ChatItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChatItemDelegate(QWidget *parent = nullptr);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    void drawSys(QPainter* painter, const QStyleOptionViewItem &option) const ;
};

#endif // WIDGET_CHATITEMDELEGATE_H
