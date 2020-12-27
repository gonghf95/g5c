#include "src/widget/Chat.h"
#include "src/widget/ChatItemDelegate.h"
#include "src/widget/ScrollBar.h"
#include "src/entity/Message.h"

#include <QScrollBar>
#include <QStringListModel>
#include <QStandardItemModel>

Chat::Chat(QWidget *parent) : QListView(parent),
    delegate_(new ChatItemDelegate(this)),
    scrollBar_(new ScrollBar(this))
{
    const QString style = "QListView{border:none;}";

    message msg1;
    msg1.msg_type = MSG_SYSTEM;
    msg1.text = "11:32";
    QVariant var1;
    var1.setValue(msg1);

    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item1 = new QStandardItem();
    item1->setData(var1, Qt::UserRole);
    model->appendRow(item1);

    setModel(model);
    setItemDelegate(delegate_);
    setVerticalScrollMode(ScrollPerPixel);
    setStyleSheet(style);
    setVerticalScrollBar(scrollBar_);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

Chat::~Chat()
{
    delete delegate_;
}
