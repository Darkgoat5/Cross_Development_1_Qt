#include "movie.h"

Movie::Movie(QString Name, QString Genre, QDate Release, int Score) {
    m_name = Name;
    m_genre = Genre;
    m_release = Release;
    m_score = Score;
}

QString Movie::name()
{
    return m_name;
}

QString Movie::genre()
{
    return m_genre;
}

QDate Movie::release()
{
    return m_release;
}

int Movie::score()
{
    return m_score;
}


