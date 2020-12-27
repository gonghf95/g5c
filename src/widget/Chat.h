#ifndef WIDGET_CHAT_H
#define WIDGET_CHAT_H

#include <QListView>

class ScrollBar;
class ChatItemDelegate;
class Chat : public QListView
{
    Q_OBJECT
public:
    explicit Chat(QWidget *parent = nullptr);
    virtual ~Chat();

private:
    ChatItemDelegate* delegate_;
    ScrollBar* scrollBar_;
};

#endif // WIDGET_CHATPANEL_H
