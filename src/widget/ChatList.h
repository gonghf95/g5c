#ifndef CHATLIST_H
#define CHATLIST_H

#include <QListView>

class ScrollBar;
class ChatListItemDelegate;
class ChatList : public QListView
{
    Q_OBJECT
public:
    explicit ChatList(QWidget *parent = 0);
    virtual ~ChatList();
    
private:
    ChatListItemDelegate* delegate_;
    ScrollBar* scrollBar_;
};

#endif // CHATLIST_H
