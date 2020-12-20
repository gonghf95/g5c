#include "src/app/default/DefaultFunc.h"
#include "ui_DefaultFunc.h"
#include "src/app/FuncId.h"

FuncWidget *DefaultFuncCreator::create(MainWindow *win)
{
    return new DefaultFunc(win);
}

DefaultFunc::DefaultFunc(MainWindow *parent) :
    WorkWidget(parent, FUNC_ID_DEFAULT),
    ui(new Ui::DefaultFunc)
{
    ui->setupUi(this);
}

DefaultFunc::~DefaultFunc()
{
    delete ui;
}

