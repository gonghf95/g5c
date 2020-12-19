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
    style += "QScrollBar{width: 8px; background: rgb(230,230,230);}";
    style += "QScrollBar::handle:vertical{background-color:rgb(185,185,185);border-radius:4px;}";
    style += "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{background-color:transparent;}";
    style += "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical{background-color:transparent;}";
    //style += "QScrollBar::handle:vertical:hover{background-color:rgb(185,185,185);border-radius:4px;}";

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
