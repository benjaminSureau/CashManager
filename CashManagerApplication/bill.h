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
#include <map>
#include "cashier.h"
#include "product.h"
#include "listener.h"

using namespace std;

/**
 * \enum typePaiement_enum
 * \brief Constantes de type de paiement
 *
 * typePaiement_enum est une série de constantes prédéfinie pour les modes
 * de paiement disponibles
 */
enum typePaiement_enum {
    check,
    card,
    cash
};

class Bill
{
private:
public:
    static Bill* instance;/*!< Instance de la facture (évite d'avoir 2 facture ouvertes en même temps */
    map<Product*, int> products;/*!< Liste des produits associés au nombre de chacun dans le panier */
    int _id; /*!< bill id */
    QDateTime _sellingDate; /*!< printing date of the bill */
    QString _paymentMode; /*!< payment mode (card, check, cash) */
    Cashier *_cashier; /*!< the cashier that prints the bill */
    //typePaiement_enum paiementUtilise;/*!< Type de paiement utilisé */

    Bill();
    Bill(int id, QDateTime sellDate, QString paymentMode, Cashier *cashier);

    static Bill* getInstance();

    Cashier* getCashier();
    /**
     * \fn QString toString()
     * \brief string representation of the object
     *
     * \param
     * \return a string representation of the object for testing purposes
     */
    QString toString();


    /**
     * \fn map<Product*, int> getProducts();
     *
     * \return Liste des produits associés au nombre de chacun dans le panier
     */
    map<Product*, int> getProducts();

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
};

#endif // BILL_H
