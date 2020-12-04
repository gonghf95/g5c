#include "src/frame/FuncWidget.h"
#include "src/frame/MainWindow.h"

FuncWidget::FuncWidget(MainWindow *win, FUNC_ID func_id)
    : QWidget(win),
      window_(win),
      funcId_(func_id),
      keepAlive_(true)
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
