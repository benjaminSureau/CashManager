#include "cashier.h"

Cashier::Cashier(int id, QString name, int code) : _id(id), _name(name), _code(code)
{

}

QString Cashier::toString(){
    QString qs = QString("Cashier: id:%1;name:%2;code:%3").arg(_id).arg(_name).arg(_code);
    return qs;
}
