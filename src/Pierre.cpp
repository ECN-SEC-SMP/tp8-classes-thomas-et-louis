#include "Pierre.h"

#include <stdlib.h>
#include <time.h>

Pierre::Pierre(int maxX, int maxY)
    : Animal(maxX, maxY)
{
    this->nom = "🪨 ";
    this->setVivant(false);
}

void Pierre::setAttaque()
{
    this->typeAttaque = Attaque(0);
}

void Pierre::deplace(int maxX, int maxY)
{
    // no move
}