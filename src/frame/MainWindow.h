#ifndef G5C_FRAME_MAINWINDOW_H
#define G5C_FRAME_MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QVariant>

#define WIN_DEFAULT_WIDTH 859
#define WIN_DEFAULT_HEIGHT 584

class LeftBar;
class FuncWidget;
class FuncWidgetCreator;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    virtual ~MainWindow();

    void registerFuncWidget(int func_id, FuncWidgetCreator* creator);

    bool switchTo(int func_id);
    bool switchTo(int func_id, const QMap<QString, QVariant> &args);

private:
    void initUI();
    void initConnect();
    FuncWidget* createFuncWidget(int);
    bool switchTo(FuncWidget** from, FuncWidget** to, const QMap<QString, QVariant>& args);

    LeftBar* leftBar_;

    QMap<int, FuncWidgetCreator*> funcWidgetCreators_;
    QMap<int, FuncWidget*> funcWidgets_;

    FuncWidget* activeFuncWidget_;
    FuncWidget* activeWorkWidget_;
};

#endif /* G5C_FRAME_MAINWINDOW_H */
