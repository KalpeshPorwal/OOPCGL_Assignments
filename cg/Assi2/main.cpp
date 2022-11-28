#include "clipping.h"

#include <QApplication>
#include<QWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clipping w;
    w.show();
    return a.exec();
}
