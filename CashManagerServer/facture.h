#ifndef FACTURE_H
#define FACTURE_H

/**
 * \file facture.h
 * \brief Facture du client en cours
 * \author ACU
 * \version 0.1
 * \date 17 décembre 2018
 *
 * Suivi du passage en caisse
 *
 */

#include <string>
#include <time.h>
#include "product.h"
#include <map>

using namespace std;

/**
 * \enum typePaiement_enum
 * \brief Constantes de type de paiement
 *
 * typePaiement_enum est une série de constantes prédéfinie pour les modes
 * de paiement disponibles
 */
enum typePaiement_enum {
    cheque,
    carte,
    espece
};


class Facture
{
public:
    static Facture* getInstance();

    /**
     * \fn string setCaissier(string nom);
     *
     * \param Nom du caissier
     */
    void setCaissier(string nom);

    /**
     * \fn void setDate(time_t date);
     *
     * \param Date du paiement
     */
    void setDate(time_t date);

    /**
     * \fn string getCaissier();
     *
     * \return Nom du caissier
     */
    string getCaissier();

    /**
     * \fn map<Product*, int> getProducts();
     *
     * \return Liste des produits associés au nombre de chacun dans le panier
     */
    map<Product*, int> getProducts();

    /**
     * \fn time_t getDate();
     *
     * \return Date du paiement
     */
    time_t getDate();

    /**
     * \fn void addProduct(Product* p);
     *
     * \param Ajoute un produit au panier, augmente son nombre s'il existe déjà
     */
    void addProduct(Product* p);

    /**
     * \fn void reinit();
     *
     * \param Réinitialise le panier pour un nouveau client
     */
    void reinit();
private:
    static Facture* instance;/*!< Instance de la facture (évite d'avoir 2 facture ouvertes en même temps */
    map<Product*, int> products;/*!< Liste des produits associés au nombre de chacun dans le panier */
    Facture();
    string caissier;/*!< Nom du caissier qui à validé la commande */
    time_t datePaiement;/*!< Date à laquelle le paiement à été effectué */
    typePaiement_enum paiementUtilise;/*!< Type de paiement utilisé */
};

#endif // FACTURE_H
