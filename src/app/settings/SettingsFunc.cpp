#include "src/app/settings/SettingsFunc.h"
#include "ui_SettingsFunc.h"

FuncWidget *SettingsFuncCreator::create(MainWindow *window)
{
    return new SettingsFunc(window);
}

SettingsFunc::SettingsFunc(MainWindow *window)
    : FuncWidget(window, FUNC_ID_SETTINGS),
      ui(new Ui::SettingsFunc)
{
    ui->setupUi(this);

    initData();
    initUI();
    initConnect();
}

void SettingsFunc::slotSwitchButtonClicked()
{
    mainWindow()->switchTo(FUNC_ID_TEST);
}

void SettingsFunc::initData()
{
    setKeepAlive(false);
}

void SettingsFunc::initUI()
{

}

void SettingsFunc::initConnect()
{
    connect(ui->btn_switch, SIGNAL(clicked()), SLOT(slotSwitchButtonClicked()));
}
