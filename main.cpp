#include <QtGui/QApplication>
#include "mwall.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mWall w;
    w.show();
    return a.exec();
}
