#include "facture.h"
#include "categorie.h"
#include "product.h"
#include <string>

using namespace std;

int main() {
    Facture* fac = Facture::getInstance();
    Categorie *cat = new Categorie("cat test", 20);
    Product* p = new Product("code", "nom",1,cat);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    fac->addProduct(p);
    for (auto itr = fac->getProducts().begin(); itr != fac->getProducts().end(); ++itr) {
        printf("%s : %d\n",string(itr->first->getCode()).c_str(), itr->second);
    }
}
