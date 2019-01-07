/**
  * \file createbill.h
  * \brief the creation of the bill
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * prints the bill as a pdf file
  *
  */
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

    /**
     * \fn void createCss(int billId)
     * \brief writes the header of the pdf
     *
     * \param billId
     * \return
     */
    void createCss(int billId);
    /**
     * \fn void addElem(Bill_Product b)
     * \brief adds the current bill_product to the pdf file
     *
     * \param Bill_Product b
     * \return
     */
    void addElem(Bill_Product b);
    /**
     * \fn void endCss(float ttc, float ht, float taxes)
     * \brief adds the footer to the pdf file
     *
     * \param (float ttc, float ht, float taxes) the bill totals
     * \return
     */
    void endCss(float ttc, float ht, float taxes);

public:
    QString css; /*!< the content of the bill to be printed */

};

#endif // CREATEBILL_H
