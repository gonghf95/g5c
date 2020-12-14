#ifndef G5C_APP_DEFAULTFUNC_H
#define G5C_APP_DEFAULTFUNC_H

#include "src/frame/WorkWidget.h"

class DefaultFunc : public WorkWidget
{
public:
    explicit DefaultFunc(MainWindow* win);
    virtual ~DefaultFunc();
};

class DefaultFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget * create(MainWindow *);
};

#endif
