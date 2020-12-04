#include "src/app/test/TestFunc.h"
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

    initUI();
    initConnect();
}

void TestFunc::slotSwitchButtonClicked()
{
    mainWindow()->switchTo(FUNC_ID_SETTINGS);
}

void TestFunc::initUI()
{
}

void TestFunc::initConnect()
{
    connect(ui->btn_switch, SIGNAL(clicked()), SLOT(slotSwitchButtonClicked()));
}
