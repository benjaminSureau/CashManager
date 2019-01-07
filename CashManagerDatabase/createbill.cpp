/**
 * \file bill.cpp
 * \brief création de facture.
 * \author Thomas
 * \version 0.2
 * \date 02 janvier 2019
 *
 * Ce programme permet de créer et imprimer les factures
 *
 */

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
    createCss();

    QTextDocument document;

    document.setHtml(css);
    document.print(&printer);
}

QString CreateBill::currDate()
{
    QDate date = QDate::currentDate();
    return date.toString("dd.MM.yyyy");
}

void CreateBill::createCss()
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
    qint16 i = 3;
    QString num = QString::number(i);
    css+= num;

    css+= "</div>"
          "<div align=right>"
          " EUR"
          "</div>";

    css +="<div align=left>Pc nul a chier</div>"
          "<div align=right>9</div>"
          "<br>";
    css +="<div align=left>Pc nul a chier</div>"
          "<div align=right>9</div>"
          "<br>";

    css +="<div align=right>TTC: ";
    QString ttc = QString::number(i);
    css+= ttc;
    css +="</div>";
    css +="<div align=right>Total HT: ";
    QString ht = QString::number(i);
    css+= ht;
    css += " Total Taxes: ";
    QString t = QString::number(i);
    css+= t;
    css +="</div>";



}
