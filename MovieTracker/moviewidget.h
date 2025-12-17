#ifndef MOVIEWIDGET_H
#define MOVIEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "movie.h"
#include "star.h"

class MovieWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MovieWidget(Movie &movie, QColor color, QWidget *parent = nullptr);

private:
    QLabel *m_infoLabel;
    StarWidget *m_starWidget;
};

#endif // MOVIEWIDGET_H
