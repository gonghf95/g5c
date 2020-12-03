#ifndef G5C_FRAME_MAINWINDOW_H
#define G5C_FRAME_MAINWINDOW_H

#include "src/app/FuncId.h"

#include <QMainWindow>
#include <QMap>
#include <QVariant>

namespace g5c
{

namespace frame
{

class FuncWidget;
class FuncWidgetCreator;
class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget* parent = 0);

    void registerFuncWidget(FUNC_ID, FuncWidgetCreator*);

    bool switchTo(FUNC_ID func_id);
    bool switchTo(FUNC_ID func_id, const QMap<QString, QVariant> &args);

    // FUNC_ID activeFuncId() const { return activeFuncId_; }

private:
    FuncWidget* createFuncWidget(FUNC_ID, const QMap<QString, QVariant>&);

    FuncWidget* activeFuncWidget_;
    QMap<FUNC_ID, FuncWidgetCreator*> funcWidgetCreators_;
    QMap<FUNC_ID, FuncWidget*> funcWidgets_;
};

} // namespace frame

} // namespace g5c

#endif /* G5C_FRAME_MAINWINDOW_H */
