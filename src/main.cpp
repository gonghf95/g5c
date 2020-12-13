#include "src/frame/Application.h"
#include "src/frame/MainWindow.h"
#include "src/app/FuncId.h"
#include "src/app/test/TestFunc.h"
#include "src/app/settings/SettingsFunc.h"

int main(int argc, char* argv[])
{
    Application app(argc, argv);

    MainWindow win;
    win.registerFuncWidget(FUNC_ID_TEST, new TestFuncCreator);
    win.registerFuncWidget(FUNC_ID_SETTINGS, new SettingsFuncCreator);
    win.switchTo(FUNC_ID_TEST);
    win.show();

    return app.exec();
}
