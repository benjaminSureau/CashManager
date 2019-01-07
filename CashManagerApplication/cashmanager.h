#ifndef CASHMANAGER_H
#define CASHMANAGER_H

#include <QObject>

class CashManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textField READ getTextField WRITE changeValue NOTIFY textFieldChanged)
public:
    explicit CashManager(QObject *parent = nullptr);

    QString getTextField();

signals:
    void textFieldChanged();

public slots:
    void checkUser(const QString &code);

private:
    QString textField;
    void changeValue(const QString &digit);
};
#endif // CASHMANAGER_H
