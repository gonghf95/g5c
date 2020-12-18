#ifndef G5_FRAME_FUNCWIN_H
#define G5_FRAME_FUNCWIN_H

#include <QWidget>

#define FUNCWIDGET_START_X 60
#define FUNCWIDGET_START_Y 0
#define FUNCWIDGET_DEFAULT_WIDTH 250
#define FUNCWIDGET_DEFAULT_HEIGHT 584

class MainWindow;
class FuncWidget : public QWidget
{
    Q_OBJECT
public:

    int funcId() const { return funcId_; }

    virtual void active(const QMap<QString, QVariant> &args);
    virtual void inactive();
    virtual bool canSwitch();

    bool keepAlive() const { return keepAlive_; }
    void setKeepAlive(bool alive) { keepAlive_ = alive; }

    bool isWorkWidget() const { return isWorkWidget_; }

protected:
    FuncWidget(MainWindow* win, int func_id);
    virtual ~FuncWidget();

    MainWindow* mainWindow() const { return window_; }

private:
    friend class WorkWidget;

    MainWindow* window_;
    int funcId_;
    bool keepAlive_;
    bool isWorkWidget_;
};

class FuncWidgetCreator
{
public:
    virtual FuncWidget* create(MainWindow*) = 0;
};

#endif /* G5_FRAME_FUNCWIN_H */
