#ifndef G5C_FRAME_APP_H
#define G5C_FRAME_APP_H

#include <QApplication>
#include <QEvent>

class App : public QApplication
{
public:
    App(int& argc, char** argv);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    void initData();
};

#endif /* G5C_FRAME_APP_H */
