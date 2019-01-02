#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>
#include <iostream>

class Categorie
{
private:
    int _id;
    QString _name;
    float _tax;
public:
    Categorie(int id, QString name, float tax);
    QString toString();
};

#endif // CATEGORIE_H
