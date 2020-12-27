#ifndef CHAT_CHATFUNC_H
#define CHAT_CHATFUNC_H

#include "src/frame/WorkWidget.h"

namespace Ui
{
class ChatFunc;
}

class ChatFunc : public WorkWidget
{
public:
    explicit ChatFunc(MainWindow* window);
    virtual ~ChatFunc();

private:
    Ui::ChatFunc* ui;
};

class ChatFuncCreator : public FuncWidgetCreator
{
public:
    FuncWidget * create(MainWindow *) override;
};

#endif
