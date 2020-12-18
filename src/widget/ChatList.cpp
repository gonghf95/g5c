#include "src/widget/ChatList.h"

ChatList::ChatList(QWidget *parent) :
    QListView(parent)
{
    setVerticalScrollMode(ScrollPerPixel);
}

ChatList::~ChatList()
{
}
