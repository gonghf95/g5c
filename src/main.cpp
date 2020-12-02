#include "src/frame/G5cApp.h"
#include "src/frame/G5cMainWin.h"

int main(int argc, char* argv[])
{
    g5c::frame::G5cApp app(argc, argv);

    g5c::frame::G5cMainWin win;
    win.show();

    return app.exec();
}
