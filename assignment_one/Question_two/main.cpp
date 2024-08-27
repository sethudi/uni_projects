#include <QApplication>
#include "software.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Software test;
    test.show();

    return a.exec();
}
