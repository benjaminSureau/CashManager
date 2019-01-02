#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "categorie.h"

using namespace std;

class Product
{
public:
    Product(string c, string n, float p, Categorie* cat);
    string getCode();
    string getNom();
    float getPrix();
    float getPrixAvecTaxes();
    Categorie* getCategorie();
    bool operator <(const Product& p) const;
private:
    string code;
    string nom;
    float prix;
    Categorie* categorie;
};

#endif // PRODUCT_H
