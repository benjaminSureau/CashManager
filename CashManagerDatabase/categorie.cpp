#include "categorie.h"

Categorie::Categorie(int id, QString name, float tax) : _id(id), _name(name), _tax(tax)
{

}

QString Categorie::toString(){
    QString qs = QString("Categorie: id:%1;name:%2;tax:%3").arg(_id).arg(_name).arg(_tax);
    return qs;
}
