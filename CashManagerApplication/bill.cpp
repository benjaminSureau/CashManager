#include "bill.h"

Bill::Bill(int id, QDateTime sellDate, QString paymentMode, Cashier *cashier) : _id(id), _sellingDate(sellDate),
    _paymentMode(paymentMode), _cashier(cashier)
{

}

Cashier* Bill::getCashier(){
    return _cashier;
}

QString Bill::toString(){
    QString qs = QString("Bill: id:%1;date:%2;paymentMode:%3;").arg(_id).arg(_sellingDate.toString("dd/MM/yyyy hh:mm:ss")).arg(_paymentMode);
    qs.append(_cashier->toString());
    return qs;
}
