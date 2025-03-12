#pragma once

#include <string>

class Attaque
{
private:
    int typeAttaque; // 0: pierre, 1: papier, 2: ciseaux
public:
    Attaque();
    Attaque(int a);
    ~Attaque();
    int getTypeAttaque() const;
    bool resoudreAttaque(Attaque &a) const;
    std::string getNomAttaque() const;
};