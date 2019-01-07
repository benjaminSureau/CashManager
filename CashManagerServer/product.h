#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * \file product.h
 * \brief Produit
 * \author ACU
 * \version 0.1
 * \date 20/12/2018
 *
 */

#include <string>
#include "categorie.h"

using namespace std;

class Product
{
public:
    Product(string c, string n, double p, Categorie* cat);

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
private:
    string code; /*!< Code barre du produit */
    string nom; /*!< Nom du produit */
    double prix; /*!< prix sans taxe */
    Categorie* categorie; /*!< Catégorie du produit */
};

#endif // PRODUCT_H
