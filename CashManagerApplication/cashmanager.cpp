#include "cashmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>

CashManager::CashManager(QObject *parent) : QObject(parent)
{
    addBill("hello", 22.22);
    addBill("hello2", 289.00);
}


void CashManager::addBill(QString name, float price) {

    changeValue2(name);
    changeValuePrice(QString::number(price));
}

void CashManager::changeValue2(const QString &digit)
{
text1.append("\n");
    text1.append(digit);
    emit textFieldChanged2();
}

QString CashManager::getTextField2()
{
    return text1;
}

void CashManager::changeValuePrice(const QString &digit)
{
    text2.append("\n");

    text2.append(digit+ " €");
    emit textFieldChangedPrice();
}

QString CashManager::getTextFieldPrice()
{
    return text2;
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

void CashManager::checkUser(const QString &code)
{
    //TODO check user id
    qDebug() << code;
}
