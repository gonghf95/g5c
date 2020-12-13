#include "src/frame/Application.h"
#include <QTextCodec>

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
    initData();
}

bool Application::eventFilter(QObject *watched, QEvent *event)
{
    return QApplication::eventFilter(watched, event);
}

void Application::initData()
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForCStrings(codec);
}
