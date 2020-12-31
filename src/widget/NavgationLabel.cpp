#include "NavgationLabel.h"

#include <QPainter>
#include <QDebug>

class NavgationLabelDetail
{
public:
    NavgationLabelDetail(NavgationLabel* holder)
        : holder_(holder)
    {

    }

    int calcPointInTextRectIndex(int x, int y)
    {
        for(int i=0; i<textRects_.size(); ++i)
        {
            if(textRects_[i].contains(x, y))
            {
                return i;
            }
        }
        return -1;
    }

    void computeTextRect()
    {
        const int holderWidth = holder_->width();
        const int holderHeight = holder_->height();
        const int textStringsSize = holder_->labelStrings_.size();

        int maxRectWidth = -1;
        int maxRectHeight = -1;

        QFontMetrics fm(holder_->font());
        for(int i=0; i<textStringsSize; ++i)
        {
            QRect textRect = fm.boundingRect(holder_->labelStrings_[i]);
            if(textRect.width() > maxRectWidth)
                maxRectWidth = textRect.width();
            if(textRect.height() > maxRectHeight)
                maxRectHeight = textRect.height();
        }

        const int totalHeight = textStringsSize * (maxRectHeight + holder_->labelSpacing());
        int startY = (holderHeight - totalHeight)/2;

        textRects_.clear();
        for(int i=0; i<textStringsSize; i++)
        {
            textRects_.push_back(QRect(holderWidth-maxRectWidth-10, startY, maxRectWidth+5, maxRectHeight));
            startY += holder_->labelSpacing();
            startY += maxRectHeight;
        }

        holder_->update();
    }

    void drawTextLabel(QPainter& painter)
    {
        for(int i=0; i<textRects_.size() &&
            (i<holder_->labelStrings_.size()); ++i)
        {
            if(i == holder_->activeLabelIndex_)
            {
                painter.save();

                QPen pen;
                pen.setColor(Qt::red);

                painter.setPen(pen);
                painter.drawText(textRects_[i], Qt::AlignRight, holder_->labelStrings_[i]);

                painter.restore();
                continue;
            }

            painter.drawText(textRects_[i], Qt::AlignRight, holder_->labelStrings_[i]);
        }
    }

    QRect activeTextRect()
    {
        if((holder_->activeLabelIndex_ < 0 ) ||
                (holder_->activeLabelIndex_ >= textRects_.size()))
            return QRect();
        return textRects_[holder_->activeLabelIndex_];
    }

private:
    NavgationLabel* holder_;
    QVector<QRect> textRects_;
};

NavgationLabel::NavgationLabel(QWidget *parent) :
    QWidget(parent),
    activeLabelIndex_(0),
    labelSpacing_(8),
    detail_(new NavgationLabelDetail(this))
{
}

NavgationLabel::~NavgationLabel()
{
    delete detail_;
}

void NavgationLabel::addLabel(const QString &text)
{
    labelStrings_.push_back(text);
    detail_->computeTextRect();
    update();
}

void NavgationLabel::mousePressEvent(QMouseEvent *event)
{
    int ret;
    if((ret = detail_->calcPointInTextRectIndex(event->x(), event->y())) >= 0)
    {
        setActiveIndex(ret);
    }
}

void NavgationLabel::wheelEvent(QWheelEvent *event)
{
    if(Qt::Vertical == event->orientation())
    {
        if(event->delta() < 0)
        {
            activeLabelIndex_ = (activeLabelIndex_+1)>=labelStrings_.size()?labelStrings_.size()-1:activeLabelIndex_+1;
        }
        else
        {
            activeLabelIndex_ = (activeLabelIndex_-1)<0?0:activeLabelIndex_-1;
        }
    }
    update();
}

void NavgationLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QFont font;
    font.setPixelSize(16);

    QPen pen;
    pen.setColor(QColor("#a8a8a8"));

    painter.setPen(pen);
    painter.setFont(font);

    painter.drawLine(width()-1, 0, width()-1, height());

    detail_->drawTextLabel(painter);

    painter.save();

    QRect activeTextRect = detail_->activeTextRect();

    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawEllipse(width()-1, activeTextRect.y()+labelSpacing()/2-2, 16, 16);
    painter.restore();
}

void NavgationLabel::setActiveIndex(int index)
{
    if(index<0 || index>=labelStrings_.size())
        return;

    activeLabelIndex_ = index;
    update();
}
