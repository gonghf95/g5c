#ifndef G5C_FRAME_APP_H
#define G5C_FRAME_APP_H

#include <QApplication>
#include <QEvent>

namespace g5c
{

namespace frame
{

class App : public QApplication
{
public:
    App(int& argc, char** argv);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    void initData();
};

} // namespace frame

} // namespace g5c

#endif /* G5C_FRAME_APP_H */
