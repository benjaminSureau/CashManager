#include "bill_product.h"

Bill_Product::Bill_Product(Bill *bill, Product *product, int quantity) : _bill(bill), _product(product), _quantity(quantity)
{

}

Bill* Bill_Product::getBill(){
    return _bill;
}

Product* Bill_Product::getProduct(){
    return _product;
}

QString Bill_Product::toString(){
    QString qs = QString("Bill_Product: quantity:%1;").arg(_quantity);
    qs.append(_bill->toString());
    qs.append(QString(";"));
    qs.append(_product->toString());
    return qs;
}
