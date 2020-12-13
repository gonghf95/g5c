#ifndef G5C_FRAME_WORKWIDGET_H
#define G5C_FRAME_WORKWIDGET_H

#include "src/frame/FuncWidget.h"

#define WORKWIDGET_START_X 310
#define WORKWIDGET_START_Y 0
#define WORKWIDGET_DEFAULT_WIDTH 549
#define WORKWIDGET_DEFAULT_HEIGHT 584

class MainWindow;
class WorkWidget : public FuncWidget
{
protected:
    WorkWidget(MainWindow* win, int func_id);
    virtual ~WorkWidget();
};

#endif
