#ifndef G5C_FRAME_LEFTBAR_H
#define G5C_FRAME_LEFTBAR_H

#include <QWidget>
#include <QMenu>

#define LEFTBAR_DEFAULT_WIDTH 60
#define LEFTBAR_DEFAULT_HEIGHT 584

namespace Ui
{
class LeftBar;
}

class MainWindow;
class LeftBar : public QWidget
{
    Q_OBJECT
public:
    enum ActivePanel
    {
        AP_CHAT,
        AP_CONTACT,
        AP_FAVOURITE
    };

    explicit LeftBar(MainWindow *parent = nullptr);
    virtual ~LeftBar();

    void setActivePanel(ActivePanel ap)
    { updateActivePanelState(ap); }
    ActivePanel activePanel() const
    { return activePanel_; }

signals:
    void sigActivePanelChanged(LeftBar::ActivePanel);

protected:
    MainWindow* mainWindow() { return window_; }

private slots:
    void slotPanelButtonClicked();

private:
    void initUI();
    void initConnect();

    void updateActivePanelState(ActivePanel);

    MainWindow* window_;
    Ui::LeftBar* ui;
    ActivePanel activePanel_;

    QMenu* moreMenu_;
};

#endif // G5C_FRAME_LEFTBAR_H
