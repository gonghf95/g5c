#ifndef G5_FRAME_FUNCWIN_H
#define G5_FRAME_FUNCWIN_H

#include "src/app/FuncId.h"

#include <QWidget>

namespace g5c
{

namespace frame
{

class MainWindow;
class FuncWidget : public QWidget
{
public:
    FuncWidget(MainWindow* win, FUNC_ID func_id);

    FUNC_ID fundId() const { return funcId_; }

    virtual void active(const QMap<QString, QVariant> &args);
    virtual void inactive();
    virtual bool canSwitch();

    void setKeepAlive(bool alive) { keepAlive_ = alive; }
    bool keepAlive() const { return keepAlive_; }

protected:
    MainWindow* mainWin() const { return window_; }

private:
    MainWindow* window_;
    FUNC_ID funcId_;
    bool keepAlive_;
};

class FuncWidgetCreator
{
public:
    virtual FuncWidget* create(const QMap<QString, QVariant> &args) = 0;
};

} // namespace frame

} // namespace g5c

#endif /* G5_FRAME_FUNCWIN_H */
