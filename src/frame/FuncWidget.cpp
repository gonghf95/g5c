#include "src/frame/FuncWidget.h"
#include "src/frame/MainWindow.h"

FuncWidget::FuncWidget(MainWindow *win, FUNC_ID func_id)
    : QWidget(win),
      window_(win),
      funcId_(func_id),
      keepAlive_(true)
{
    setGeometry(FUNCWIDGET_START_X, FUNCWIDGET_START_Y, FUNCWIDGET_DEFAULT_WIDTH, FUNCWIDGET_DEFAULT_HEIGHT);
}

FuncWidget::~FuncWidget()
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
