/**
  * \file databasehandler.h
  * \brief database handler
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the class that handles connections and interactions to the database
  *
  */
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
    QSqlDatabase _cashmanager; /*!< handles the connections to the CashManager database */
    QSqlDatabase _common_products; /*!< handles the connections to the CommonProducts database */
public:
    DataBaseHandler();
    /**
     * \fn QList<Bill> selectAllBill()
     * \brief select all bills from the database
     *
     * \param
     * \return a list of all bills from the database
     */
    QList<Bill> selectAllBill();
    /**
     * \fn Bill* selectBill(int id)
     * \brief select a bill from the database
     *
     * \param id of the bill to select
     * \return a bill from the database
     */
    Bill* selectBill(int id);
    /**
     * \fn Bill* selectLastBill()
     * \brief select last bill from the database
     *
     * \param
     * \return a bill from the database
     */
    Bill* selectLastBill();
    /**
     * \fn bool insertBill(QString paymentMode, int cashier)
     * \brief inserts the given bill in the db
     *
     * \param the informations of the bill to insert
     * \return true if the bill was successfully inserted
     */
    bool insertBill(QString paymentMode, int cashier);
    /**
     * \fn QList<Categorie> selectAllCategorie()
     * \brief select all categorie from the database
     *
     * \param
     * \return a list of all categories from the database
     */
    QList<Categorie> selectAllCategorie();
    /**
     * \fn Categorie* selectCategorie(int id)
     * \brief select a categorie from the database
     *
     * \param id of the categorie to select
     * \return a categorie from the database
     */
    Categorie* selectCategorie(int id);
    /**
     * \fn bool insertCategorie(QString name, float tax)
     * \brief inserts the given categorie in the db
     *
     * \param the informations of the categorie to insert
     * \return true if the categorie was successfully inserted
     */
    bool insertCategorie(QString name, float tax);
    /**
     * \fn QList<Bill_Product> selectAllBill_Product()
     * \brief select all bill_products from the database
     *
     * \param
     * \return a list a of all bill_products from the database
     */
    QList<Bill_Product> selectAllBill_Product();
    /**
     * \fn Bill* selectBill_Product(QString codeProd, int idBill)
     * \brief select a bill_product from the database
     *
     * \param ids of the bill_product to select
     * \return a bill_product from the database
     */
    Bill_Product* selectBill_Product(QString codeProd, int idBill);
    /**
     * \fn bool insertBill_Product(int bill, QString product, int quantity)
     * \brief inserts the given bill_product in the db
     *
     * \param the informations of the bill_product to insert
     * \return true if the bill_product was successfully inserted
     */
    bool insertBill_Product(int bill, QString product, int quantity);
    /**
     * \fn QList<Product> selectAllProduct()
     * \brief select all products from the database
     *
     * \param
     * \return a list of all products from the database
     */
    QList<Product> selectAllProduct();
    /**
     * \fn Product* selectProduct(QString code)
     * \brief select a product from the database
     *
     * \param ids of the product to select
     * \return a product from the database
     */
    Product* selectProduct(QString code);
    /**
     * \fn bool insertProduct(QString code, QString name, QString price, int categorie)
     * \brief inserts the given product in the db
     *
     * \param the informations of the product to insert
     * \return true if the product was successfully inserted
     */
    bool insertProduct(QString code, QString name, QString price, int categorie);
    /**
     * \fn QList<Cashier> selectAllCashier()
     * \brief select all cashiers from the database
     *
     * \param
     * \return a list of all cashiers from the database
     */
    QList<Cashier> selectAllCashier();
    /**
     * \fn Cashier* selectCashier(int id)
     * \brief select a cashier from the database
     *
     * \param ids of the cashier to select
     * \return a cashier from the database
     */
    Cashier* selectCashier(int id);
    /**
     * \fn bool insertCashier(QString name, int code)
     * \brief inserts the given cashier in the db
     *
     * \param QString name, int code of the cashier to insert
     * \return true if the cashier was successfully inserted
     */
    bool insertCashier(QString name, int code);
    /**
     * \fn QList<Product> selectAllProduct()
     * \brief select all products from the database with the given bill id
     *
     * \param idBill the id of the bills to get
     * \return a list of bill_products from the database
     */
    QList<Bill_Product> selectBill_ProductByBill(int idBill);
    /**
     * \fn QList<Product> selectAllProduct()
     * \brief select all products from the database with the given code product
     *
     * \param codeProduct the code of the products to get
     * \return a list of bill_products from the database
     */
    QList<Bill_Product> selectBill_ProductByProduct(QString codeProd);
};

#endif // DATABASEHANDLER_H
