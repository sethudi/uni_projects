#include <QApplication>
#include "highlightfile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HighlightFile test;
    test.show();

    return a.exec();
}
