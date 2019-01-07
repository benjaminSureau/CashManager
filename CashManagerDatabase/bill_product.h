/**
  * \file bill_product.h
  * \brief the bill_product DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the bill_product object from the database that links the
  * bills and their related products
  *
  */
#ifndef BILL_PRODUCT_H
#define BILL_PRODUCT_H

#include "bill.h"
#include "product.h"


class Bill_Product
{
private:
public:
    Bill *_bill; /*!< the linked bill */
    Product *_product; /*!< the linked product */
    int _quantity; /*!< the quantity of this product in the bill */
    Bill_Product(Bill *bill, Product *product, int quantity);
    Product* getProduct();
    Bill* getBill();
    /**
     * \fn QString toString()
     * \brief string representation of the object
     *
     * \param
     * \return a string representation of the object for testing purposes
     */
    QString toString();
};

#endif // BILL_PRODUCT_H
