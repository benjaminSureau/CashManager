#include "categorie.h"

Categorie::Categorie(string name, double tax)
{
    this->name = name;
    this->taxe = tax;

}

string Categorie::getName() {
    return this->name;
}

double Categorie::getTaxe() {
    return this->taxe;
}
