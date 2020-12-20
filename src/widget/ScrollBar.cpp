#include "ScrollBar.h"

ScrollBar::ScrollBar(QWidget *parent)
    : QScrollBar(parent),
      animation_(new QPropertyAnimation(this, "value"))
{
    animation_->setDuration(380);
    animation_->setEasingCurve(QEasingCurve::InOutCubic);

    QString style = "QScrollBar{width: 8px; background: rgb(230,230,230);}";
    style += "QScrollBar::handle:vertical{background-color:rgb(185,185,185);border-radius:4px;}";
    style += "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{background-color:transparent;}";
    style += "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical{background-color:transparent;}";
    setStyleSheet(style);
}

void ScrollBar::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta() * 8 * 0.3;
    int value = this->value();

    if(animation_->state() == QAbstractAnimation::Stopped)
    {
        animation_->setEndValue(value - delta);
        animation_->start();
    }
}
