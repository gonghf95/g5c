#include "src/app/chat/ChatFunc.h"
#include "src/app/FuncId.h"
#include "ui_ChatFunc.h"

FuncWidget *ChatFuncCreator::create(MainWindow *win)
{
    return new ChatFunc(win);
}

ChatFunc::ChatFunc(MainWindow *window) : WorkWidget(window, FUNC_ID_CHAT),
    ui(new Ui::ChatFunc)
{
    ui->setupUi(this);
}

ChatFunc::~ChatFunc()
{
    delete ui;
}
