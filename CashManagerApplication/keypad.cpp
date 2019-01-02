#include "keypad.h"
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
    qDebug()<<code;
}
