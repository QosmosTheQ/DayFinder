#include "dayfinder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DayFinder w;
    w.show();
    return a.exec();
}
