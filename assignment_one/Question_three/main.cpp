#include <QApplication>
#include "musicmodelview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MusicModelView test;
    test.show();

    return a.exec();
}
