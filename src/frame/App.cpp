#include "src/frame/App.h"
#include <QTextCodec>

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    initData();
}

bool App::eventFilter(QObject *watched, QEvent *event)
{
    return QApplication::eventFilter(watched, event);
}

void App::initData()
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForCStrings(codec);
}
