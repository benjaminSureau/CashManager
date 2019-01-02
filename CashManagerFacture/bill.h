#ifndef BILL_H
#define BILL_H

#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QObject>
#include <QWidget>


class Bill
{
public:
    Bill();

private slots:
    void pdf(QString filename);
    void document(QString filename);

    QString currDate();
    void createCss();

public:
    QString css;

};

#endif // BILL_H
