#ifndef G5C_FUNCWIDGETCONTROLLER_H
#define G5C_FUNCWIDGETCONTROLLER_H

#include <QMap>
#include <QVariant>

class MainWindow;
class FuncWidget;
class FuncWidgetCreator;
class FuncWidgetController
{
public:
    explicit FuncWidgetController(MainWindow* win);
    virtual ~FuncWidgetController();

    void registerFuncWidget(int func_id, FuncWidgetCreator* creator);

    bool switchTo(int func_id);
    bool switchTo(int func_id, const QMap<QString, QVariant> &args);

private:
    FuncWidget* createFuncWidget(int);
    bool switchTo(FuncWidget** from, FuncWidget** to, const QMap<QString, QVariant>& args);

    MainWindow* window_;

    QMap<int, FuncWidgetCreator*> funcWidgetCreators_;
    QMap<int, FuncWidget*> funcWidgets_;

    FuncWidget* activeFuncWidget_;
    FuncWidget* activeWorkWidget_;
};

#endif // G5C_FUNCWIDGETCONTROLLER_H
