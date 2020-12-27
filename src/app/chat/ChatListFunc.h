#ifndef APP_CHATLISTFUNC_H
#define APP_CHATLISTFUNC_H

#include "src/frame/FuncWidget.h"

namespace Ui
{
class ChatListFunc;
}

class ChatListFunc : public FuncWidget
{
public:
    explicit ChatListFunc(MainWindow*);
    virtual ~ChatListFunc();

    void active(const QMap<QString, QVariant> &args);

private:
    Ui::ChatListFunc* ui;
};

class ChatListFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget * create(MainWindow *);
};

#endif
