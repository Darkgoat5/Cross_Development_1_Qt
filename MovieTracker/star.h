#ifndef STARWIDGET_H
#define STARWIDGET_H

#include <QWidget>
#include <QColor>

class StarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StarWidget(QWidget *parent = nullptr);

    void setStarColor(const QColor &c) { m_color = c; update(); }
    void setEmptyStarColor(const QColor &c) { m_emptyColor = c; update(); }
    void setScore(int score);   // 0–5

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPolygonF makeStar(const QRectF &bounds) const;

    QColor m_color = Qt::yellow;
    QColor m_emptyColor = Qt::lightGray;
    int m_score = 0;
    const int m_maxStars = 5;
};

#endif // STARWIDGET_H
