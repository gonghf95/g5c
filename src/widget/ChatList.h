#ifndef WIDGET_CHATLIST_H
#define WIDGET_CHATLIST_H

#include <QListView>
#include <QEvent>

class ScrollBar;
class ChatListItemDelegate;
class ChatList : public QListView
{
    Q_OBJECT
public:
    explicit ChatList(QWidget *parent = 0);
    virtual ~ChatList();

protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    
private:
    ChatListItemDelegate* delegate_;
    ScrollBar* scrollBar_;
};

#endif // CHATLIST_H
