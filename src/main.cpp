#include "src/frame/App.h"
#include "src/frame/MainWindow.h"

int main(int argc, char* argv[])
{
    g5c::frame::App app(argc, argv);

    g5c::frame::MainWindow win;

    //    win.registerFuncWidget();

    win.show();

    return app.exec();
}
