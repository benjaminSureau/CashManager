#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>

using namespace std;

class Categorie
{
public:
    Categorie(string name, float tax);
    string getName();
    float getTaxe();
private:
    string name;
    float taxe;
};

#endif // CATEGORIE_H
