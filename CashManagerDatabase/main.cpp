/*#include <QCoreApplication>
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
    std::cout << std::endl;
    std::cout << std::endl;

    QList<Bill_Product> bill_prods;
    bill_prods = db->selectBill_ProductByBill(1);

    for(Bill_Product b : bill_prods){
        std::cout << b.toString().toLocal8Bit().constData() << std::endl;
    }
    //db->insertBill_Product(3, "3287432975", 5);
    return a.exec();
}
*/
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QApplication>

#include "createbill.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBaseHandler *db = new DataBaseHandler();

    //CreateBill *b = new CreateBill(db, 1);
    QList<Bill> bills = db->selectAllBill();
    for(Bill b : bills){
        std::cout << b.toString().toUtf8().constData() << std::endl;
    }
    std::cout << std::endl;
    db->insertBill("cash", 3);
    bills = db->selectAllBill();
    for(Bill b : bills){
        std::cout << b.toString().toUtf8().constData() << std::endl;
    }

    return a.exec();
}
