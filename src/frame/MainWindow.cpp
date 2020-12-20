#include "src/frame/MainWindow.h"
#include "src/frame/FuncWidgetController.h"
#include "src/app/FuncId.h"
#include "src/common/Logger.h"
#include "src/app/default/DefaultFunc.h"
#include "src/app/chat/ChatFunc.h"
#include "src/app/test/TestFunc.h"
#include "src/app/settings/SettingsFunc.h"

#include <QDesktopWidget>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      leftBar_(new LeftBar(this)),
      funcWidgetController_(new FuncWidgetController(this))
{
    initData();
    initUi();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete leftBar_;
    delete funcWidgetController_;
}

void MainWindow::slotActivePanelChanged(LeftBar::ActivePanel, const QVariant &data)
{
    int func_id = data.toInt();
    funcWidgetController_->switchTo(func_id);
}

void MainWindow::initData()
{
    funcWidgetController_->registerFuncWidget(FUNC_ID_DEFAULT, new DefaultFuncCreator);
    funcWidgetController_->registerFuncWidget(FUNC_ID_CHAT, new ChatFuncCreator);
    funcWidgetController_->registerFuncWidget(FUNC_ID_TEST, new TestFuncCreator);
    funcWidgetController_->registerFuncWidget(FUNC_ID_SETTINGS, new SettingsFuncCreator);

    leftBar_->bind(LeftBar::AP_CHAT, FUNC_ID_CHAT);
    leftBar_->bind(LeftBar::AP_CONTACT, FUNC_ID_TEST);
    leftBar_->bind(LeftBar::AP_FAVOURITE, FUNC_ID_SETTINGS);
}

void MainWindow::initUi()
{
    QDesktopWidget *desktop = QApplication::desktop();
    int startX = (desktop->width() - WIN_DEFAULT_WIDTH)/2;
    int startY = (desktop->height() - WIN_DEFAULT_HEIGHT)/2;
    setGeometry(startX, startY, WIN_DEFAULT_WIDTH, WIN_DEFAULT_HEIGHT);
    setFixedSize(WIN_DEFAULT_WIDTH, WIN_DEFAULT_HEIGHT);

    funcWidgetController_->switchTo(FUNC_ID_CHAT);
    funcWidgetController_->switchTo(FUNC_ID_DEFAULT);
}

void MainWindow::initConnect()
{
    connect(leftBar_, SIGNAL(sigActivePanelChanged(LeftBar::ActivePanel, QVariant)), SLOT(slotActivePanelChanged(LeftBar::ActivePanel, QVariant)));
}

