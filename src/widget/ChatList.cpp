#include "src/widget/ChatList.h"
#include "src/widget/ChatListItemDelegate.h"
#include "src/widget/ScrollBar.h"

#include <QScrollBar>
#include <QStringListModel>

ChatList::ChatList(QWidget *parent)
    : QListView(parent),
      delegate_(new ChatListItemDelegate(this)),
      scrollBar_(new ScrollBar(this))
{
    QStringList list;
    for(int i=0; i<20; ++i)
        list << QString::number(i);

    QStringListModel* model = new QStringListModel(this);
    model->setStringList(list);

    QString style = "QListView{background-color:rgb(230,230,230); border:none;}";

    setModel(model);
    setItemDelegate(delegate_);
    setVerticalScrollMode(ScrollPerPixel);
    setStyleSheet(style);
    setVerticalScrollBar(scrollBar_);
}

ChatList::~ChatList()
{
    delete delegate_;
}
