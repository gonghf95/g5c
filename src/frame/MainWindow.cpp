#include "src/frame/MainWindow.h"
#include "src/frame/LeftBar.h"
#include "src/frame/FuncWidget.h"
#include "src/public/Logger.h"

#include <QDesktopWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      leftBar_(new LeftBar(this)),
      activeFuncWidget_(NULL),
      activeWorkWidget_(NULL)
{
    initUI();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete leftBar_;
}

void MainWindow::registerFuncWidget(int func_id, FuncWidgetCreator *creator)
{
    if(creator == NULL)
        return ;

    if(!funcWidgetCreators_.contains(func_id))
    {
        funcWidgetCreators_.insert(func_id, creator);
    }
}

bool MainWindow::switchTo(int func_id)
{
    QMap<QString, QVariant> args;
    return switchTo(func_id, args);
}

bool MainWindow::switchTo(int func_id, const QMap<QString, QVariant> &args)
{
    FuncWidget* func_widget = createFuncWidget(func_id);
    if(!func_widget)
    {
        return false;
    }

    /// WorkWidget
    if(func_widget->isWorkWidget())
    {
        return switchTo(&activeWorkWidget_, &func_widget, args);
    }

    /// FuncWidget
    return switchTo(&activeFuncWidget_, &func_widget, args);
}

void MainWindow::initUI()
{
    QDesktopWidget *desktop = QApplication::desktop();
    int startX = (desktop->width() - WIN_DEFAULT_WIDTH)/2;
    int startY = (desktop->height() - WIN_DEFAULT_HEIGHT)/2;
    setGeometry(startX, startY, WIN_DEFAULT_WIDTH, WIN_DEFAULT_HEIGHT);
    setFixedSize(WIN_DEFAULT_WIDTH, WIN_DEFAULT_HEIGHT);
}

void MainWindow::initConnect()
{

}

FuncWidget *MainWindow::createFuncWidget(int func_id)
{
    if(funcWidgets_.contains(func_id) &&
            funcWidgets_[func_id])
    {
        return funcWidgets_[func_id];
    }

    FuncWidgetCreator* creator = funcWidgetCreators_.value(func_id, NULL);
    if(!creator)
    {
        return NULL;
    }

    FuncWidget* new_func_widget = creator->create(this);
    if(new_func_widget)
    {
        funcWidgets_[func_id] = new_func_widget;
    }
    return new_func_widget;
}

bool MainWindow::switchTo(FuncWidget **from, FuncWidget **to, const QMap<QString, QVariant> &args)
{
    if(!(*from))
    {
        *from = *to;
        (*from)->active(args);
        return true;
    }

    if((*from)->funcId() == (*to)->funcId())
        return true;

    if(!(*from)->canSwitch())
        return false;

    if((*from)->keepAlive())
    {
        (*from)->inactive();
    }
    else
    {
        funcWidgets_[(*from)->funcId()] = NULL;
        (*from)->deleteLater();
    }

    *from = *to;
    (*from)->active(args);
    return true;
}
