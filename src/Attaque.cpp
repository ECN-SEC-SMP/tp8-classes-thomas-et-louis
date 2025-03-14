#include "Attaque.h"

#include <stdlib.h>
#include <time.h>

Attaque::Attaque()
{
    this->typeAttaque = rand() % 3;
}

Attaque::Attaque(int type)
{
    this->typeAttaque = type;
}

int Attaque::getTypeAttaque() const
{
    return this->typeAttaque;
}

bool Attaque::resoudreAttaque(Attaque &a) const
{
    int typeAtt = a.getTypeAttaque();
    if ((this->typeAttaque == 0 && typeAtt == 2) 
        || (this->typeAttaque == 1 && typeAtt == 0) 
        || (this->typeAttaque == 2 && typeAtt == 1)) return true;
    if ((this->typeAttaque == 0 && typeAtt == 1) 
        || (this->typeAttaque == 1 && typeAtt == 2) 
        || (this->typeAttaque == 2 && typeAtt == 0)) return false;
    else
    {
        return rand() % 2;
    }
    
}

std::string Attaque::getNomAttaque() const
{
    switch (this->typeAttaque)
    {
    case 0:
        return "Pierre";
        break;
    case 1:
        return "Feuille";
        break;
    case 2:
        return "Ciseaux";
        break;

    default:
        break;
    }
    return "";
}
