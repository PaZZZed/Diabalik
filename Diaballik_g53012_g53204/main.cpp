#include "mwdiaballik.h"
#include "option.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Option w;
    w.show();
    return a.exec();
}

