#include "star.h"
#include <QPainter>
#include <QtMath>

//https://doc.qt.io/qt-6/qtwidgets-itemviews-stardelegate-example.html

StarWidget::StarWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(30);
    setMinimumWidth(150);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void StarWidget::setScore(int score)
{
    if (score < 0) score = 0;
    if (score > m_maxStars) score = m_maxStars;
    m_score = score;
    update();
}

void StarWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int starSpacing = 5;
    int availableWidth = width() - (m_maxStars + 1) * starSpacing;
    int starSize = qMin(availableWidth / m_maxStars, height() - 10);

    for (int i = 0; i < m_maxStars; ++i) {
        QRectF r(starSpacing + i * (starSize + starSpacing),
                 (height() - starSize)/2,
                 starSize,
                 starSize);

        QPolygonF star = makeStar(r);
        p.setBrush(i < m_score ? m_color : m_emptyColor);
        p.setPen(Qt::black);
        p.drawPolygon(star);
    }

}

QPolygonF StarWidget::makeStar(const QRectF &bounds) const
{
    QPolygonF poly;
    QPointF c = bounds.center();
    qreal rOuter = bounds.width() / 2;
    qreal rInner = rOuter * 0.5;
    int verts = 10;

    for (int i = 0; i < verts; ++i) {
        qreal angle = M_PI/2 + i * M_PI/5;
        qreal r = (i % 2 == 0) ? rOuter : rInner;
        poly << QPointF(c.x() + r * cos(angle),
                        c.y() - r * sin(angle));
    }
    return poly;
}
