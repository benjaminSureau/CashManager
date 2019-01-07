#ifndef BILL_H
#define BILL_H

#include <QDateTime>
#include "cashier.h"


class Bill
{
private:
    int _id;
    QDateTime _sellingDate;
    QString _paymentMode;
    Cashier *_cashier;
public:
    Bill(int id, QDateTime sellDate, QString paymentMode, Cashier *cashier);
    Cashier* getCashier();
    QString toString();
};

#endif // BILL_H
