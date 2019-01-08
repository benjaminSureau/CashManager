#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "categorie.h"
#include "facture.h"
#include "product.h"
#include <map>


TEST_CASE( "Create and start a game", "[createPlayer]" ) {
    Facture* facture = Facture::getInstance();
    REQUIRE(facture == nullptr);
    Categorie* c;
    c = new Categorie("Alcool", 19.5);
    REQUIRE(c != nullptr);
    REQUIRE(c->getName() == "Alcool");
    REQUIRE(c->getTaxe() == 19.5);


    Categorie* c2 = new Categorie("Bonbons", 20);
    Product *p1 = new Product("0112547615", "vodka", 12.3, c);
    Product *errorProduct = new Product("0112547615", "vodka", 12.3, c2);
    REQUIRE (p1->getPrixAvecTaxes() < errorProduct->getPrixAvecTaxes());

    REQUIRE (p1->getNom() == "vodka");
    REQUIRE (p1->getCategorie()->getName() == "Alcool");

    Product *p2 = new Product("0111547615", "biere", 4.2, c);
    Product *p3 = new Product("0112547915", "champagne", 24.3, c);

    REQUIRE(Facture::getInstance()->getProducts().size() == 0);

    Facture::getInstance()->addProduct(p1);

    REQUIRE(Facture::getInstance()->getProducts().size() == 1);
    Facture::getInstance()->addProduct(p1);
    Facture::getInstance()->addProduct(p1);
    Facture::getInstance()->addProduct(p1);
    Facture::getInstance()->addProduct(p1);
    Facture::getInstance()->addProduct(p1);
    Facture::getInstance()->addProduct(p1);
    REQUIRE(Facture::getInstance()->getProducts().size() == 1);
    for (auto& x: Facture::getInstance()->getProducts()) {
        REQUIRE(x.second == 7);
    }
    Facture::getInstance()->addProduct(p2);
    Facture::getInstance()->addProduct(p3);
    REQUIRE(Facture::getInstance()->getProducts().size() == 3);

}
