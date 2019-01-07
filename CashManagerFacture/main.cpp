#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QApplication>


#include "bill.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Bill *b = new Bill();
    return a.exec();
}
