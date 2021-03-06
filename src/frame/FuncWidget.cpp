#include "src/frame/FuncWidget.h"
#include "src/frame/MainWindow.h"

FuncWidget::FuncWidget(MainWindow *win, int func_id)
    : QWidget(win),
      window_(win),
      funcId_(func_id),
      keepAlive_(true),
      isWorkWidget_(false)
{
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(231, 230, 230));

    setPalette(palette);
    setAutoFillBackground(true);
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
