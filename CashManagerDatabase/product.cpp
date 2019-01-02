#include "product.h"

Product::Product(QString code, QString name, float price, Categorie *categorie) : _code(code), _name(name),
    _price(price), _categorie(categorie)
{

}

Categorie* Product::getCategorie(){
    return _categorie;
}

QString Product::toString(){
    QString qs = QString("Product: code:%1;name:%2;price:%3;").arg(_code).arg(_name).arg(_price);
    qs.append(_categorie->toString());
    return qs;
}
