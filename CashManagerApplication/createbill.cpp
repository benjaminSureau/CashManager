#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QApplication>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QFont>
#include <QTextCharFormat>
#include <QTextDocument>
#include <QTextCursor>
#include <QDate>

#include "createbill.h"

CreateBill::CreateBill(DataBaseHandler *db, int billId)
{
    QList<Bill_Product> bill = db->selectBill_ProductByBill(billId);
    QString filename = "C:/Users/43cb886c4537/Documents/cashmanager/CashManager/facture.pdf";
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::NativeFormat);
    printer.setPaperSize(QPrinter::Comm10E);
    printer.setOutputFileName(filename);

    QFont headerFont("Times New Roman", 6);
    QFont titleFont("Times New Roman", 8, QFont::Bold);

    css = "";
    createCss(bill.first()._bill->_id);

    float ttc;
    float ht;
    float taxes;
    for(Bill_Product b : bill){
        addElem(b);
        ht+=b._product->_price * b._quantity;
        ttc=b._product->_price * b._quantity * ((100+b._product->_categorie->_tax)/100);
    }
    taxes = ttc - ht;
    endCss(ttc, ht, taxes);


    QTextDocument document;

    document.setHtml(css);
    document.print(&printer);
}

void CreateBill::createCss(int billId)
{
    css = "<div align=center>"
          "POMMED’EPITECH <br>"
          "street 34/56A<br>"
          "33000 Bordeaux"
          "</div><br>"
          "Le ";

    QDate date = QDate::currentDate();
    QString dateS = date.toString("dd.MM.yyyy");
    css+= dateS;
    css+= "<div>"
          "Ticket N° ";
    QString num = QString::number(billId);
    css+= num;

    css+= "</div>"
          "<div align=right>"
          " EUR"
          "</div>";
}

void CreateBill::addElem(Bill_Product b)
{
    QString name = b._product->_name;
    css +="<div align=left>";
    css += name;
    css += " ";
    css += QString::number(b._product->_price);

    css += "€x";
    css += QString::number(b._quantity);
    css += "</div>"
          "<div align=right>";
    int valArtTot = b._product->_price * b._quantity;
    QString num = QString::number(valArtTot);
    css += num;
    css += "€</div>"
          "<br>";
}

void CreateBill::endCss(float ttc, float ht, float taxes)
{
    css +="<div align=right>TTC: ";
    QString Sttc = QString::number(ttc);
    css+= Sttc;
    css +="€</div>";
    css +="<div align=right>Total HT: ";
    QString Sht = QString::number(ht);
    css+= Sht;
    css += "€ Total Taxes: ";
    QString St = QString::number(taxes);
    css+= St;
    css +="€</div>";
}
