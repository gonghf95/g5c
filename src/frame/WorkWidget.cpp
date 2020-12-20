#include "src/frame/WorkWidget.h"

#include <QPalette>

WorkWidget::WorkWidget(MainWindow *win, int func_id)
    : FuncWidget(win, func_id)
{

    isWorkWidget_ = true;

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, QColor(245, 245, 245));

    setPalette(palette);
    setAutoFillBackground(true);
    setGeometry(WORKWIDGET_START_X, WORKWIDGET_START_Y, WORKWIDGET_DEFAULT_WIDTH, WORKWIDGET_DEFAULT_HEIGHT);
}

WorkWidget::~WorkWidget()
{

}
