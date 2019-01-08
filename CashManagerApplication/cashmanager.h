#ifndef CASHMANAGER_H
#define CASHMANAGER_H

#include <QObject>
#include "databasehandler.h"
#include "createbill.h"

class CashManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textField READ getTextField WRITE changeValue NOTIFY textFieldChanged)
    Q_PROPERTY(QString productName READ getTextField2 WRITE changeValue2 NOTIFY textFieldChanged2) //productName
    Q_PROPERTY(QString priceValue READ getTextFieldPrice WRITE changeValuePrice NOTIFY textFieldChangedPrice) //priceValue
    Q_PROPERTY(QString totalBill READ getTextFieldTotalBill WRITE changeValueTotalBill NOTIFY textFieldChangedTotalBill)

public:
    explicit CashManager(QObject *parent = nullptr);

    QString getTextField();
    QString getTextField2();
    QString getTextFieldPrice();
    QString getTextFieldTotalBill();
     void addBill(QString name, float price);
     void clearBill();
signals:
    void textFieldChanged();
    void textFieldChanged2();
    void textFieldChangedPrice();
    void textFieldChangedTotalBill();

public slots:
    void checkUser(const QString &code);
    void createBill(const QString &code);

private:
    QString textField;
    QString productName;
    QString priceValue;
    QString totalBill = "0";

    void changeValue(const QString &digit);
    void changeValue2(const QString &digit);
    void changeValuePrice(const QString &digit);
    void changeValueTotalBill(const QString &digit);

};
#endif // CASHMANAGER_H
