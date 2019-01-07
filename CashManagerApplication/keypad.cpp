#include "keypad.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QDebug>

Keypad::Keypad(QObject *parent) : QObject(parent)
{
}


void Keypad::changeValue(const QString &digit)
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

QString Keypad::getTextField()
{
    return textField;
}

void Keypad::checkUser(const QString &code)
{
    //TODO check user id
    qDebug() << code;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/board.qml")));
}
