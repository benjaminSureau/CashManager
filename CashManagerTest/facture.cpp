#include "facture.h"
#include <map>
#include <string>
#include "product.h"

Facture* Facture::instance = nullptr;

using namespace std;

Facture::Facture()
{
}

Facture* Facture::getInstance() {
    if (instance == nullptr) {
        instance = new Facture();
    }
    return instance;
}

void Facture::setCaissier(string nom){
   this->caissier = nom;
}

void Facture::setDate(time_t date){
    this->datePaiement = date;
}

string Facture::getCaissier(){
    return this->caissier;
}

map<Product*, int> Facture::getProducts(){
    return products;
}

time_t Facture::getDate(){
    return datePaiement;
}

void Facture::addProduct(Product* p) {
    auto it = products.find(p);
    if (it != products.end()) {
        it->second = ++it->second;
    } else {
        products.insert({p, 1});
    }
}

void Facture::reinit() {
    products.clear();
}
