#include "product.h"

Product::Product(string c, string n, float p, Categorie* cat)
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

float Product::getPrix() {
    return this->prix;
}

Categorie* Product::getCategorie() {
    return this->categorie;
}


float Product::getPrixAvecTaxes() {
    return this->categorie->getTaxe() * this->prix;
}

bool Product::operator <(const Product& p) const
{
    return p.code < code;
}
