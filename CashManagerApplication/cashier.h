/**
  * \file cashier.h
  * \brief the cashier DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the cashier object from the database (contains the name of the cashier)
  *
  */
#ifndef CASHIER_H
#define CASHIER_H

#include <QString>
#include <iostream>

class Cashier
{
private:
public:
    int _id; /*!< id of the cashier */
    QString _name; /*!< name of the cashier */
    int _code; /*!< code of the cashier */
    Cashier(int id, QString name, int code);
    /**
     * \fn QString toString()
     * \brief string representation of the object
     *
     * \param
     * \return a string representation of the object for testing purposes
     */
    QString toString();
};

#endif // CASHIER_H
