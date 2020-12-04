#ifndef G5_FRAME_FUNCWIN_H
#define G5_FRAME_FUNCWIN_H

#include "src/app/FuncId.h"

#include <QWidget>

class MainWindow;
class FuncWidget : public QWidget
{
    Q_OBJECT
public:
    FuncWidget(MainWindow* win, FUNC_ID func_id);

    FUNC_ID funcId() const { return funcId_; }

    virtual void active(const QMap<QString, QVariant> &args);
    virtual void inactive();
    virtual bool canSwitch();

    bool keepAlive() const { return keepAlive_; }
    void setKeepAlive(bool alive) { keepAlive_ = alive; }

protected:
    MainWindow* mainWindow() const { return window_; }

private:
    MainWindow* window_;
    FUNC_ID funcId_;
    bool keepAlive_;
};

class FuncWidgetCreator
{
public:
    virtual FuncWidget* create(MainWindow*) = 0;
};

#endif /* G5_FRAME_FUNCWIN_H */
