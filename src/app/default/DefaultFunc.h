#ifndef DEFAULTFUNC_H
#define DEFAULTFUNC_H

#include "src/frame/WorkWidget.h"

namespace Ui {
class DefaultFunc;
}

class MainWindow;
class DefaultFunc : public WorkWidget
{
    Q_OBJECT
public:
    explicit DefaultFunc(MainWindow *parent);
    virtual ~DefaultFunc();

private:
    Ui::DefaultFunc *ui;
};

class DefaultFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget * create(MainWindow *);
};

#endif // DEFAULTFUNC_H
