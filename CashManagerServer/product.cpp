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


float Product::getPrixAvecTaxes() {
    return ((100 + static_cast<float>(this->categorie->getTaxe())) * static_cast<float>(this->prix)) / 100;
}

bool Product::operator <(const Product& p) const
{
    return p.code < code;
}
