#include "movietracker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MovieTracker w;
    w.show();
    return a.exec();
}
