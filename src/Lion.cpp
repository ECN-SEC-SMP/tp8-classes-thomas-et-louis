#include "Lion.h"

Lion::Lion(int maxX, int maxY)
    : Animal(maxX, maxY)
{
    this->nom = "🦁";
    this->setVivant(true);
    this->vie = 1;
}

void Lion::setAttaque()
{
    int att_type = rand() % 2 + 1;
    this->typeAttaque = Attaque(att_type);
}

void Lion::deplace(int maxX, int maxY)
{
    int dx = rand() % 2 ? 1 : -1;
    int dy = rand() % 2 ? 1 : -1;
    this->x += dx;
    this->y += dy;
    if (this->x >= maxX) this->x %= maxX;
    if (this->y >= maxY) this->y %= maxY;
    if (this->x < 0) this->x += maxX;
    if (this->y < 0) this->y += maxY;
}