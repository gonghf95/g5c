#include "src/frame/App.h"
#include <QTextCodec>

using namespace g5c::frame;

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    initData();
}

bool App::eventFilter(QObject *, QEvent *)
{
}

void App::initData()
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
}
