#ifndef PRODUCT_H
#define PRODUCT_H

#include "categorie.h"


class Product
{
private:
public:
    QString _code;
    QString _name;
    float _price;
    Categorie *_categorie;
    Product(QString code, QString name, float price, Categorie *categorie);
    Categorie *getCategorie();
    QString toString();
};

#endif // PRODUCT_H
