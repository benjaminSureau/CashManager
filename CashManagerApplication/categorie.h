/**
  * \file categorie.h
  * \brief the categorie DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the categorie object from the database (contains the types of products and the tax)
  *
  */
#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>
#include <iostream>

class Categorie
{
private:
public:
    int _id; /*!< id of the categorie */
    QString _name; /*!< name of the categorie */
    float _tax; /*!< tax of this categorie*/
    Categorie(int id, QString name, float tax);
    /**
     * \fn QString toString()
     * \brief string representation of the object
     *
     * \param
     * \return a string representation of the object for testing purposes
     */
    QString toString();
};

#endif // CATEGORIE_H
