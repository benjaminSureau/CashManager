#ifndef CATEGORIE_H
#define CATEGORIE_H

/**
 * \file categorie.h
 * \brief Categorie du produit
 * \author ACU
 * \version 0.2
 * \date 21 décembre 2018
 *
 * Permet de gérer de manière efficace les taxes
 *
 */

#include <string>

using namespace std;

class Categorie
{
public:
    Categorie(string name, float tax);

    /**
     * \fn string getName();
     *
     * \return Nom de la catégorie du produit
     */
    string getName();

    /**
     * \fn double getTaxe();
     *
     * \return pourcentage de taxe appliquée au produit
     */
    double getTaxe();
private:
    string name;/*!< Nom de la catégorie */
    float taxe;/*!< Pourcentage de taxe appliquée aux produits de cette catégorie */
};

#endif // CATEGORIE_H
