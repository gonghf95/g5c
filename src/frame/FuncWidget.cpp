#include "src/frame/FuncWidget.h"

using namespace g5c::frame;

FuncWidget::FuncWidget(MainWindow *win, FUNC_ID func_id)
    : window_(win),
      funcId_(func_id)
{
}

void FuncWidget::active(const QMap<QString, QVariant> &)
{
    show();
}

void FuncWidget::inactive()
{
    hide();
}

bool FuncWidget::canSwitch()
{
    return true;
}
