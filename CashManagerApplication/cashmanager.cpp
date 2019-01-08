#include "cashmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>

CashManager::CashManager(QObject *parent) : QObject(parent)
{
    addBill("hello", 22.22);
    addBill("hello2", 289.00);
    bill = new Bill();

}

void CashManager::clearBill(){
    totalBill = "0";
    emit textFieldChangedTotalBill();
    productName.clear();
    emit textFieldChanged2();
    priceValue.clear();
    emit textFieldChanged();
}

void CashManager::addBill(QString name, float price) {
    changeValue2(name);

    float total = price + totalBill.toFloat();
    changeValuePrice(QString::number(price));
    changeValueTotalBill(QString::number(total));
}

void CashManager::changeValueTotalBill(const QString &digit)
{
    totalBill = digit;
    emit textFieldChangedTotalBill();
}

QString CashManager::getTextFieldTotalBill()
{
    return totalBill;
}

void CashManager::changeValue2(const QString &digit)
{
productName.append("\n");
    productName.append(digit);
    emit textFieldChanged2();
}

QString CashManager::getTextField2()
{
    return productName;
}

void CashManager::changeValuePrice(const QString &digit)
{
    priceValue.append("\n");

    priceValue.append(digit+ " €");
    emit textFieldChangedPrice();
}

QString CashManager::getTextFieldPrice()
{
    return priceValue;
}


void CashManager::changeValue(const QString &digit)
{
    if (digit == "CA") {
        textField = "";
    } else if (digit == "C") {
        textField = textField.left(textField.length()-1);
    } else {
        textField.append(digit);
    }
    emit textFieldChanged();
}

QString CashManager::getTextField()
{
    return textField;
}

void CashManager::addProduct(const QString &code)
{
    DataBaseHandler *db = new DataBaseHandler();
    Product *p = db->selectProduct(code);

    if (p != nullptr){
        if(currBillId == 0){
            db->insertBill("card", 2);
            currBillId = db->selectLastBill()->_id;
        }
        Bill::getInstance()->addProduct(p);
        db->insertBill_Product(currBillId, code, 1);
        addBill(p->_name, p->getPrixAvecTaxes());
        setProperty("priceValue", p->_name);
    }
}

void CashManager::createBill(const QString &code){
    DataBaseHandler *db = new DataBaseHandler();
    if(currBillId == 0){
        currBillId = db->selectLastBill()->_id;
    }

    CreateBill *b = new CreateBill(db, currBillId);
}
