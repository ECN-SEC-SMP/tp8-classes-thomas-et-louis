#include "Ours.h"

Ours::Ours(int maxX, int maxY)
    : Animal(maxX, maxY)
{
    this->nom = "O";
    this->setVivant(true);
}

void Ours::setAttaque()
{
    this->typeAttaque = Attaque(1);
}

void Ours::deplace(int maxX, int maxY)
{
    srand(time(NULL));

    int dx = rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2);
    int dy = rand() % 2 ? (rand() % 2 ? 1 : -1) : (rand() % 2 ? 2 : -2);
    this->x += dx;
    this->y += dy;
    if (this->x > maxX) this->x %= maxX;
    if (this->y > maxY) this->y %= maxY;
    if (this->x < 0) this->x += maxX;
    if (this->y < 0) this->y += maxY;
}