#include "src/app/chat/ChatFunc.h"
#include "src/app/FuncId.h"
#include "ui_ChatFunc.h"

FuncWidget *ChatFuncCreator::create(MainWindow *win)
{
    return new ChatFunc(win);
}

ChatFunc::ChatFunc(MainWindow *win)
    : FuncWidget(win, FUNC_ID_CHAT),
      ui(new Ui::ChatFunc)
{
    ui->setupUi(this);
}

ChatFunc::~ChatFunc()
{
    delete ui;
}

void ChatFunc::active(const QMap<QString, QVariant> &args)
{
    FuncWidget::active(args);

    ui->edt_search->addAction(ui->actionSerach, QLineEdit::LeadingPosition);
}
