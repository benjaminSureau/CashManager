/**
  * \file bill.h
  * \brief the bill DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the bill object from the database (contains the date of the bill, the cashier and the payment mode)
  *
  */
#ifndef BILL_H
#define BILL_H

#include <QDateTime>
#include "cashier.h"


class Bill
{
private:
public:
    int _id; /*!< bill id */
    QDateTime _sellingDate; /*!< printing date of the bill */
    QString _paymentMode; /*!< payment mode (card, check, cash) */
    Cashier *_cashier; /*!< the cashier that prints the bill */
    Bill(int id, QDateTime sellDate, QString paymentMode, Cashier *cashier);
    Cashier* getCashier();
    /**
     * \fn QString toString()
     * \brief string representation of the object
     *
     * \param
     * \return a string representation of the object for testing purposes
     */
    QString toString();
};

#endif // BILL_H
