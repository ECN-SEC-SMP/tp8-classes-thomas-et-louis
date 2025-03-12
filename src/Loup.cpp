#include "Loup.h"

Loup::Loup(int maxX, int maxY)
    :Animal(maxX,maxY)
{
    this->nom = "🐺";
    this->setVivant(true);
}

void Loup::setAttaque()
{
    this->typeAttaque = Attaque();
}

void Loup::deplace(int maxX, int maxY)
{
    x = rand() % maxX;
    y = rand() % maxY;
}
