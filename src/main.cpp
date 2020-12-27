#include "src/frame/Application.h"
#include "src/frame/MainWindow.h"
#include "src/app/FuncId.h"
#include "src/app/default/DefaultFunc.h"
#include "src/app/chat/ChatListFunc.h"
#include "src/app/test/TestFunc.h"
#include "src/app/settings/SettingsFunc.h"

int main(int argc, char* argv[])
{
    Application app(argc, argv);

    MainWindow win;
    win.show();

    return app.exec();
}
