#ifndef G5C_APP_CHATFUNC_H
#define G5C_APP_CHATFUNC_H

#include "src/frame/FuncWidget.h"

namespace Ui
{
class ChatFunc;
}

class ChatFunc : public FuncWidget
{
public:
    explicit ChatFunc(MainWindow*);
    virtual ~ChatFunc();

    void active(const QMap<QString, QVariant> &args);

private:
    Ui::ChatFunc* ui;
};

class ChatFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget * create(MainWindow *);
};

#endif
