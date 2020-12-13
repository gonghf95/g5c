#ifndef G5C_FRAME_APPLICATION_H
#define G5C_FRAME_APPLICATION_H

#include <QApplication>
#include <QEvent>

class Application : public QApplication
{
public:
    Application(int& argc, char** argv);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    void initData();
};

#endif /* G5C_FRAME_APPLICATION_H */
