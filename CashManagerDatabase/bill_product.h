#ifndef BILL_PRODUCT_H
#define BILL_PRODUCT_H

#include "bill.h"
#include "product.h"


class Bill_Product
{
private:
    Bill *_bill;
    Product *_product;
    int _quantity;
public:
    Bill_Product(Bill *bill, Product *product, int quantity);
    Product* getProduct();
    Bill* getBill();
    QString toString();
};

#endif // BILL_PRODUCT_H
