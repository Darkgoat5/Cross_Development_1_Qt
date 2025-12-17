#include "moviewidget.h"

MovieWidget::MovieWidget(Movie &movie, QColor color, QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    m_infoLabel = new QLabel(
        QString("%1 (%2) - %3")
            .arg(movie.name())
            .arg(movie.genre())
            .arg(movie.release().toString("dd/MM/yyyy"))
        );

    m_starWidget = new StarWidget(this);
    m_starWidget->setScore(movie.score());

    m_starWidget->setStarColor(color);
    m_starWidget->setEmptyStarColor(Qt::lightGray);
    m_starWidget->setFixedHeight(30);

    layout->addWidget(m_infoLabel);
    layout->addWidget(m_starWidget);

    layout->setSpacing(10);
    layout->setContentsMargins(5,5,5,5);

    setLayout(layout);
}
