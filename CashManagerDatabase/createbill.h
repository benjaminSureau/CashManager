#ifndef CREATEBILL_H
#define CREATEBILL_H


#include <QDialog>
#include <QTcpSocket>
#include <QString>
#include <QObject>
#include <QWidget>
#include "databasehandler.h"


class CreateBill
{
public:
    CreateBill(DataBaseHandler *db, int billId);

private slots:
    void document(QString filename);

    void createCss(int billId);
    void addElem(Bill_Product b);
    void endCss(float ttc, float ht, float taxes);

public:
    QString css;

};

#endif // CREATEBILL_H
