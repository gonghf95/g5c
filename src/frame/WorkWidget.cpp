#include "src/frame/WorkWidget.h"

#include <QPalette>

WorkWidget::WorkWidget(MainWindow *win, int func_id)
    : FuncWidget(win, func_id)
{

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(231, 230, 230));

    setPalette(palette);
    setGeometry(WORKWIDGET_START_X, WORKWIDGET_START_Y, WORKWIDGET_DEFAULT_WIDTH, WORKWIDGET_DEFAULT_HEIGHT);
    setAutoFillBackground(true);
}

WorkWidget::~WorkWidget()
{

}
