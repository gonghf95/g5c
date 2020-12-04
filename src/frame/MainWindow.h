#ifndef G5C_FRAME_MAINWINDOW_H
#define G5C_FRAME_MAINWINDOW_H

#include "src/app/FuncId.h"

#include <QMainWindow>
#include <QMap>
#include <QVariant>

#define WIN_DEFAULT_WIDTH 480
#define WIN_DEFAULT_HEIGHT 320

class FuncWidget;
class FuncWidgetCreator;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);

    void registerFuncWidget(FUNC_ID, FuncWidgetCreator*);

    bool switchTo(FUNC_ID func_id);
    bool switchTo(FUNC_ID func_id, const QMap<QString, QVariant> &args);

	
private:
    FuncWidget* createFuncWidget(FUNC_ID);

    FuncWidget* activeFuncWidget_;
    QMap<FUNC_ID, FuncWidgetCreator*> funcWidgetCreators_;
    QMap<FUNC_ID, FuncWidget*> funcWidgets_;
};

#endif /* G5C_FRAME_MAINWINDOW_H */
