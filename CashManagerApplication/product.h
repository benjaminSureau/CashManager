/**
  * \file product.h
  * \brief the product DAO
  * \author Joris
  * \version 1.0
  * \date 07/01/2019
  *
  * the product object from the database (contains the code, name, price and categorie)
  *
  */
#ifndef PRODUCT_H
#define PRODUCT_H

#include "categorie.h"

using namespace std;

class Product
{
private:
public:
    QString _code; /*!< code of the product */
    QString _name; /*!< name of the product */
    float _price; /*!< price of the product (ht) */
    Categorie *_categorie; /*!< categorie of the product (contains the tax) */
    Product(QString code, QString name, float price, Categorie *categorie);

    QString toString();
    /**
     * \fn string getCode();
     *
     * \return Code du produit
     */
    string getCode();

    /**
     * \fn  string getNom();
     *
     * \return Nom du caissier
     */
    string getNom();

    /**
     * \fn float getPrix();
     *
     * \param Prix sans les taxes
     */
    double getPrix();

    /**
     * \fn float getPrixAvecTaxes();
     *
     * \return Prix avec les taxes
     */
    float getPrixAvecTaxes();

    /**
     * \fn Categorie* getCategorie();
     *
     * \return Catégorie du produit
     */
    Categorie* getCategorie();

    bool operator <(const Product& p) const;
};

#endif // PRODUCT_H
