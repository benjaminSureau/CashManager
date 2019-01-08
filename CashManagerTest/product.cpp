#include "product.h"

Product::Product(string c, string n, double p, Categorie* cat)
{
    this->code = c;
    this->nom = n;
    this->prix = p;
    this->categorie = cat;
}

string Product::getCode() {
    return this->code;
}

string Product::getNom() {
    return this->nom;
}

double Product::getPrix() {
    return this->prix;
}

Categorie* Product::getCategorie() {
    return this->categorie;
}


double Product::getPrixAvecTaxes() {
    return ((100 + this->categorie->getTaxe()) * this->prix) / 100;
}

bool Product::operator <(const Product& p) const
{
    return p.code < code;
}
