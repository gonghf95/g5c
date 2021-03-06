#include "src/app/test/TestFunc.h"
#include "src/app/FuncId.h"
#include "ui_TestFunc.h"

FuncWidget* TestFuncCreator::create(MainWindow *window)
{
    return new TestFunc(window);
}

TestFunc::TestFunc(MainWindow *window)
    : FuncWidget(window, FUNC_ID_TEST),
      ui(new Ui::TestFunc)
{
    ui->setupUi(this);

    initData();
    initUI();
    initConnect();
}

void TestFunc::slotSwitchButtonClicked()
{
    mainWindow()->switchTo(FUNC_ID_CHAT);
}

void TestFunc::initData()
{

}

void TestFunc::initUI()
{
}

void TestFunc::initConnect()
{
    connect(ui->btn_switch, SIGNAL(clicked()), this, SLOT(slotSwitchButtonClicked()));
}
