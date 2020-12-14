#include "src/app/default/DefaultFunc.h"
#include "src/app/FuncId.h"

FuncWidget *DefaultFuncCreator::create(MainWindow * win)
{
    return new DefaultFunc(win);
}

DefaultFunc::DefaultFunc(MainWindow *win)
    : WorkWidget(win, FUNC_ID_DEFAULT)
{

}

DefaultFunc::~DefaultFunc()
{

}
