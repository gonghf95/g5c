#ifndef G5C_APP_SETTINGSFUNC_H
#define G5C_APP_SETTINGSFUNC_H

#include "src/frame/FuncWidget.h"
#include "src/frame/MainWindow.h"

namespace Ui
{
class SettingsFunc;
}

class MainWindow;
class SettingsFunc : public FuncWidget
{
    Q_OBJECT
public:
    explicit SettingsFunc(MainWindow* window);
    virtual ~SettingsFunc();

private slots:
    void slotSwitchButtonClicked();

private:
    void initData();
    void initUI();
    void initConnect();

    Ui::SettingsFunc* ui;
};

class SettingsFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget* create(MainWindow *);
};

#endif
