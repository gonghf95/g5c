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
    const QString style = "QListView{border:none;background-color:transparent;}";

    ChatMsg msg1;
    QStandardItem* item1 = new QStandardItem();
    QVariant var1;
    msg1.msg_type = MSG_SYSTEM;
    msg1.text = "2020/12/31 11:32";
    var1.setValue(msg1);
    item1->setData(var1, Qt::UserRole);

    ChatMsg msg2;
    QStandardItem* item2 = new QStandardItem();
    QVariant var2;
    msg2.msg_type = MSG_RECEIVED;
    msg2.text = ".updateEditorGeometry()：确保上述组件作为编辑器时能够完整地显示出来。";
    var2.setValue(msg2);
    item2->setData(var2, Qt::UserRole);

    ChatMsg msg3;
    QStandardItem* item3 = new QStandardItem();
    QVariant var3;
    msg3.msg_type = MSG_SYSTEM;
    msg3.text = "11:32";
    var3.setValue(msg3);
    item3->setData(var3, Qt::UserRole);

    ChatMsg msg4;
    QStandardItem* item4 = new QStandardItem();
    QVariant var4;
    msg4.msg_type = MSG_RECEIVED;
    msg4.text = ".updateEditorGeometry";
    var4.setValue(msg4);
    item4->setData(var4, Qt::UserRole);

    ChatMsg msg5;
    QStandardItem* item5 = new QStandardItem();
    QVariant var5;
    msg5.msg_type = MSG_SYSTEM;
    msg5.text = "2020/12/31 11:32";
    var5.setValue(msg5);
    item5->setData(var5, Qt::UserRole);

    QStandardItemModel* model = new QStandardItemModel(this);
    model->appendRow(item1);
    model->appendRow(item2);
    model->appendRow(item3);
    model->appendRow(item4);
    model->appendRow(item5);

    setModel(model);
    setItemDelegate(delegate_);
    setVerticalScrollMode(ScrollPerPixel);
    setStyleSheet(style);
    setVerticalScrollBar(scrollBar_);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(QAbstractItemView::NoSelection);
    setUniformItemSizes(false);
}

Chat::~Chat()
{
    delete delegate_;
}
