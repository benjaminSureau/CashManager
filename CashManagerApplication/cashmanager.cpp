#include "cashmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>

CashManager::CashManager(QObject *parent) : QObject(parent)
{
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
