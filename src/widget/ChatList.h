#ifndef CHATLIST_H
#define CHATLIST_H

#include <QListView>

class ChatList : public QListView
{
    Q_OBJECT
public:
    explicit ChatList(QWidget *parent = 0);
    virtual ~ChatList();
    
};

#endif // CHATLIST_H
