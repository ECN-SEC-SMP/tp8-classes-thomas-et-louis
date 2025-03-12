#include "Loup.h"

Loup::Loup(int maxX, int maxY)
    :Animal(maxX,maxY)
{
    this->nom = "W";
    this->setVivant(true);
}

void Loup::setAttaque()
{
    this->typeAttaque = Attaque();
}

void Loup::deplace(int maxX, int maxY)
{
    srand(time(NULL));
    x = rand() % maxX;
    y = rand() % maxY;
}
