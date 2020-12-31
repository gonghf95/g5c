#ifndef NAVGATIONLABEL_H
#define NAVGATIONLABEL_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWheelEvent>

class NavgationLabelDetail;
class NavgationLabel : public QWidget
{
    Q_OBJECT
public:
    explicit NavgationLabel(QWidget *parent = 0);
    virtual ~NavgationLabel();

    void addLabel(const QString& text);
    void updateLabel(int index, const QString& text);

    void setActiveIndex(int index);
    int activeIndex() const { return activeLabelIndex_; }
    QString activeLabelText() const { return labelStrings_[activeLabelIndex_]; }

    int size() const { return labelStrings_.size(); }

    void setLabelSpacing(int spacing)
    { labelSpacing_ = spacing; }
    int labelSpacing() const
    { return labelSpacing_; }

signals:
    void sigActiveIndexChanged(int index);

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void wheelEvent(QWheelEvent *);
    
private:
    friend class NavgationLabelDetail;

    int activeLabelIndex_;
    int labelSpacing_;
    QVector<QString> labelStrings_;

    NavgationLabelDetail* detail_;
};

#endif // NAVGATIONLABEL_H
