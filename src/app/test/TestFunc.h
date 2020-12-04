#ifndef G5C_APP_TESTFUNC_H
#define G5C_APP_TESTFUNC_H

#include "src/frame/FuncWidget.h"
#include "src/frame/MainWindow.h"

namespace Ui
{
class TestFunc;
}

class TestFunc : public FuncWidget
{
public:
    explicit TestFunc(MainWindow*);

private slots:
    void slotSwitchButtonClicked();

private:
    void initUI();
    void initConnect();

    Ui::TestFunc* ui;
};

class TestFuncCreator : public FuncWidgetCreator
{
public:
    virtual FuncWidget* create(MainWindow *);
};

#endif /* G5C_APP_WINTEST_H */
