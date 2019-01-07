#ifndef CASHMANAGER_H
#define CASHMANAGER_H

#include <QObject>

class CashManager: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textField READ getTextField WRITE changeValue NOTIFY textFieldChanged)
    Q_PROPERTY(QString text1 READ getTextField2 WRITE changeValue2 NOTIFY textFieldChanged2)
       Q_PROPERTY(QString text2 READ getTextFieldPrice WRITE changeValuePrice NOTIFY textFieldChangedPrice)
public:
    explicit CashManager(QObject *parent = nullptr);

    QString getTextField();
    QString getTextField2();
     QString getTextFieldPrice();
     void addBill(QString name, float price);
signals:
    void textFieldChanged();
    void textFieldChanged2();
    void textFieldChangedPrice();

public slots:
    void checkUser(const QString &code);

private:
    QString textField;
    QString text1;
    QString text2;
    void changeValue(const QString &digit);
    void changeValue2(const QString &digit);
    void changeValuePrice(const QString &digit);
};
#endif // CASHMANAGER_H
