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

    QString currDate();
    void createCss();

public:
    QString css;

};

#endif // CREATEBILL_H
