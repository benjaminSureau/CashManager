#ifndef KEYPAD_H
#define KEYPAD_H

#include <QObject>

class Keypad : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textField READ getTextField WRITE changeValue NOTIFY textFieldChanged)
public:
    explicit Keypad(QObject *parent = nullptr);

    QString getTextField();

signals:
    void textFieldChanged();

public slots:
    void checkUser(const QString &code);

private:
    QString textField;
    void changeValue(const QString &digit);
};

#endif // KEYPAD_H
