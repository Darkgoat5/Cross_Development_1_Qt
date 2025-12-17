#ifndef MOVIETRACKER_H
#define MOVIETRACKER_H

#include <QMainWindow>
#include <movie.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MovieTracker;
}
QT_END_NAMESPACE

class MovieTracker : public QMainWindow
{
    Q_OBJECT

public:
    MovieTracker(QWidget *parent = nullptr);
    ~MovieTracker();
    void printMovies();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MovieTracker *ui;
    QList<Movie> m_movies;
    QColor m_color = Qt::yellow;
};
#endif // MOVIETRACKER_H
