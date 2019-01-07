/**
  * \file product.h
  * \brief the product DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the product object from the database (contains the code, name, price and categorie)
  *
  */
#ifndef PRODUCT_H
#define PRODUCT_H

#include "categorie.h"


class Product
{
private:
public:
    QString _code; /*!< code of the product */
    QString _name; /*!< name of the product */
    float _price; /*!< price of the product (ht) */
    Categorie *_categorie; /*!< categorie of the product (contains the tax) */
    Product(QString code, QString name, float price, Categorie *categorie);
    Categorie *getCategorie();
    QString toString();
};

#endif // PRODUCT_H
