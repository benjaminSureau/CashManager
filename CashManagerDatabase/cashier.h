#ifndef CASHIER_H
#define CASHIER_H

#include <QString>
#include <iostream>

class Cashier
{
private:
    int _id;
    QString _name;
    int _code;
public:
    Cashier(int id, QString name, int code);
    QString toString();
};

#endif // CASHIER_H
