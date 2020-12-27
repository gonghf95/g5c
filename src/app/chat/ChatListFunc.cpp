#include "src/app/chat/ChatListFunc.h"
#include "src/app/FuncId.h"
#include "ui_ChatListFunc.h"

FuncWidget *ChatListFuncCreator::create(MainWindow *win)
{
    return new ChatListFunc(win);
}

ChatListFunc::ChatListFunc(MainWindow *win)
    : FuncWidget(win, FUNC_ID_CHATLIST),
      ui(new Ui::ChatListFunc)
{
    ui->setupUi(this);
}

ChatListFunc::~ChatListFunc()
{
    delete ui;
}

void ChatListFunc::active(const QMap<QString, QVariant> &args)
{
    FuncWidget::active(args);

    ui->edt_search->addAction(ui->actionSerach, QLineEdit::LeadingPosition);
}
