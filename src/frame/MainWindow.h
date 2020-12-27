#ifndef G5C_FRAME_MAINWINDOW_H
#define G5C_FRAME_MAINWINDOW_H

#include "src/frame/LeftBar.h"

#include <QMainWindow>
#include <QMap>
#include <QVariant>

#define WIN_DEFAULT_WIDTH 859
#define WIN_DEFAULT_HEIGHT 584

class LeftBar;
class FuncWidgetController;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    virtual ~MainWindow();

    bool switchTo(int func_id);
    bool switchTo(int func_id, const QMap<QString, QVariant> &args);

private slots:
    void slotActivePanelChanged(LeftBar::ActivePanel, const QVariant& data);

private:
    void initData();
    void initUi();
    void initConnect();

    LeftBar* leftBar_;
    FuncWidgetController* funcWidgetController_;
};

#endif /* G5C_FRAME_MAINWINDOW_H */
