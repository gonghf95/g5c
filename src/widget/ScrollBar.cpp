#include "ScrollBar.h"

ScrollBar::ScrollBar(QWidget *parent)
    : QScrollBar(parent),
      animation_(new QPropertyAnimation(this, "value"))
{
    animation_->setDuration(180);
    animation_->setEasingCurve(QEasingCurve::InOutQuad);
}

void ScrollBar::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();
    int value = this->value();
    if(animation_->state() == QAbstractAnimation::Stopped)
    {
        animation_->setEndValue(value - delta);
        animation_->start();
    }
}
