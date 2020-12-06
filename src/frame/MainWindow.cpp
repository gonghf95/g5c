#include "src/frame/MainWindow.h"
#include "src/frame/LeftBar.h"
#include "src/frame/FuncWidget.h"
#include "src/public/Logger.h"

#include <QDesktopWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      activeFuncWidget_(NULL),
      leftBar_(new LeftBar(this))
{
    initUI();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete leftBar_;
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
    if(!activeFuncWidget_)
    {
        activeFuncWidget_ = createFuncWidget(func_id);
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

    if(!func_widget)
    {
        func_widget = createFuncWidget(func_id);
        if(!func_widget)
            return false;
    }

    if(activeFuncWidget_->keepAlive())
    {
        activeFuncWidget_->inactive();
    }
    else
    {
        activeFuncWidget_->deleteLater();
    }

    activeFuncWidget_ = func_widget;
    activeFuncWidget_->active(args);

    LOG_INFO(QString("Switch to: %1").arg(activeFuncWidget_->funcId()));

    return true;
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

FuncWidget *MainWindow::createFuncWidget(FUNC_ID func_id)
{
    FuncWidgetCreator* creator = funcWidgetCreators_.value(func_id, NULL);
    if(!creator)
        return NULL;

    return creator->create(this);
}
