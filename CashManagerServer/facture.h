#ifndef FACTURE_H
#define FACTURE_H

#include <string>
#include <time.h>
#include "product.h"
#include <map>

using namespace std;

enum typePaiement_enum {
    cheque,
    carte,
    espece
};


class Facture
{
public:
    static Facture* getInstance();
    void setCaissier(string nom);
    void setDate(time_t date);
    string getCaissier();
    map<Product*, int> getProducts();
    time_t getDate();
    void addProduct(Product* p);
private:
    static Facture* instance;
    map<Product*, int> products;
    Facture();
    string caissier;
    time_t datePaiement;
    typePaiement_enum paiementUtilise;
};

#endif // FACTURE_H
