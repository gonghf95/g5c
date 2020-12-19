#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollBar>
#include <QScrollEvent>
#include <QPropertyAnimation>

class ScrollBar : public QScrollBar
{
    Q_OBJECT
public:
    explicit ScrollBar(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *);

private:
    QPropertyAnimation* animation_;
};

#endif // SCROLLBAR_H
