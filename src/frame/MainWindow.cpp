#include "src/frame/MainWindow.h"
#include "src/frame/FuncWidget.h"

using namespace g5c::frame;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

void MainWindow::registerFuncWidget(FUNC_ID func_id, FuncWidgetCreator *creator)
{
    if(creator == NULL)
        return ;

    if(!funcWidgetCreators_.contains(func_id))
    {
        funcWidgetCreators_.insert(func_id, creator);
    }
}

bool MainWindow::switchTo(FUNC_ID func_id)
{
    QMap<QString, QVariant> args;
    return switchTo(func_id, args);
}

bool MainWindow::switchTo(FUNC_ID func_id, const QMap<QString, QVariant> &args)
{
    if(activeFuncWidget_ == NULL)
    {
        activeFuncWidget_ = createFuncWidget(func_id, args);
        if(!activeFuncWidget_)
        {
            return false;
        }

        activeFuncWidget_->hide();
        activeFuncWidget_->active(args);
        return true;
    }

    if(activeFuncWidget_->funcId() == func_id)
        return true;

    if(!activeFuncWidget_->canSwitch())
        return false;

    FuncWidget* func_widget = NULL;
    if(funcWidgets_.contains(func_id))
    {
        func_widget = funcWidgets_[func_id];
    }
    else
    {
        func_widget = createFuncWidget(func_id, args);
        if(!func_widget)
            return false;
    }

    if(activeFuncWidget_)
    {
        if(activeFuncWidget_->keepAlive())
        {
            activeFuncWidget_->inactive();
        }
        else
        {
            activeFuncWidget_->destroy();
        }

        funcWidgets_ = func_widget;
    }

    activeFuncWidget_->active(args);

    return true;
}

FuncWidget *MainWindow::createFuncWidget(FUNC_ID, const QMap<QString, QVariant> &)
{
}
