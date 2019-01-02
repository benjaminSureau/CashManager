#include <QCoreApplication>
#include "databasehandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataBaseHandler *db = new DataBaseHandler();
    QList<Bill> bills;
    bills = db->selectAllBill();

    for(Bill b : bills){
        std::cout << b.toString().toLocal8Bit().constData() << std::endl;
    }
    return a.exec();
}
