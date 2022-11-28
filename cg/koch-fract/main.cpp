#include "fractal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fractal w;
    w.show();
    return a.exec();
}
