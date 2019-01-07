#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDateTime>
#include <iostream>
#include <QList>

#include "bill.h"
#include "bill_product.h"
#include "cashier.h"
#include "categorie.h"
#include "product.h"

class DataBaseHandler
{
private:
    QSqlDatabase _cashmanager;
    QSqlDatabase _common_products;
public:
    DataBaseHandler();
    QList<Bill> selectAllBill();
    Bill* selectBill(int id);
    bool insertBill(QString paymentMode, int cashier);
    QList<Categorie> selectAllCategorie();
    Categorie* selectCategorie(int id);
    bool insertCategorie(QString name, float tax);
    QList<Bill_Product> selectAllBill_Product();
    Bill_Product* selectBill_Product(QString codeProd, int idBill);
    bool insertBill_Product(int bill, QString product, int quantity);
    QList<Product> selectAllProduct();
    Product* selectProduct(QString code);
    bool insertProduct(QString code, QString name, QString price, int categorie);
    QList<Cashier> selectAllCashier();
    Cashier* selectCashier(int id);
    bool insertCashier(QString name, int code);
    QList<Bill_Product> selectBill_ProductByBill(int idBill);
    QList<Bill_Product> selectBill_ProductByProduct(QString codeProd);
};

#endif // DATABASEHANDLER_H
