#pragma once

#include <string>
#include <stdlib.h>
#include <time.h>

#include "Attaque.h"


class Animal
{
protected :
    std::string nom;
    int x;
    int y;
    bool vivant;
    Attaque typeAttaque;
public:
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int x, int y);
    virtual ~Animal() = default;
    std::string getNom() const;
    int getX() const;
    int getY() const;
    bool getVivant() const;
    Attaque getAttaque() const;
    void setVivant(bool v);
    bool attaque(Animal &a);
    virtual void setAttaque() = 0; //virtuelle pure
    virtual void deplace(int maxX, int maxY) = 0; // virtuelle pure
};
