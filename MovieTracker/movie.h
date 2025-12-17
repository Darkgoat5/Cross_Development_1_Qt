#ifndef MOVIE_H
#define MOVIE_H
#include "QtWidgets"

class Movie
{
public:
    Movie(QString name, QString genre, QDate release, int score);
    void drawRating();
    QString name();
    QString genre();
    QDate release();
    int score();


private:
    QString m_name;
    QString m_genre;
    QDate m_release;
    int m_score;
};

#endif // MOVIE_H
