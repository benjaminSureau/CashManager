#include "bill.h"
#include <QThread>

Bill* Bill::instance = nullptr;

Bill::Bill(int id, QDateTime sellDate, QString paymentMode, Cashier *cashier) : _id(id), _sellingDate(sellDate),
    _paymentMode(paymentMode), _cashier(cashier)
{
    Listener listener;
    QThread* thread = new QThread;
    listener.moveToThread(thread);
    thread->start();
}

Bill::Bill()
{
    Listener listener;
    QThread* thread = new QThread;
    listener.moveToThread(thread);
    thread->start();
}

Cashier* Bill::getCashier(){
    return _cashier;
}

QString Bill::toString(){
    QString qs = QString("Bill: id:%1;date:%2;paymentMode:%3;").arg(_id).arg(_sellingDate.toString("dd/MM/yyyy hh:mm:ss")).arg(_paymentMode);
    qs.append(_cashier->toString());
    return qs;
}

Bill* Bill::getInstance() {
    if (instance == nullptr) {
        instance = new Bill();
    }
    return instance;
}

void Bill::addProduct(Product* p) {
    auto it = products.find(p);
    if (it != products.end()) {
        it->second = ++it->second;
    } else {
        products.insert({p, 1});
    }
}

void Bill::reinit() {
    products.clear();
}
