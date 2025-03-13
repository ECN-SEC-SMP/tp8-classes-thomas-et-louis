#include "Animal.h"

Animal::Animal(int maxX, int maxY)
{
    x = rand() % maxX;
    y = rand() % maxY;
}

Animal::Animal(int maxX, int maxY, int x, int y)
    : x(x), y(y)
{
    if (this->x > maxX)
    {
        this->x = maxX;
    }
    if (this->y > maxY)
    {
        this->y = maxY;
    }
}

std::string Animal::getNom() const
{
    return nom;
}

int Animal::getX() const
{
    return x;
}

int Animal::getY() const
{
    return y;
}

int Animal::getLife() const
{
    return vie;
}

int Animal::getFlag() const 
{
    return flag;
}

void Animal::setFlag()
{
    this->flag = 1;
}

void Animal::resetFlag()
{
    this->flag = 0;    
}


bool Animal::getVivant() const
{
    return vivant;
}

Attaque Animal::getAttaque() const
{
    return typeAttaque;
}

void Animal::setVivant(bool v)
{
    this->vivant = v;
}

bool Animal::attaque(Animal &a)
{
    this->setAttaque();
    a.setAttaque();
    return this->typeAttaque.resoudreAttaque(a.typeAttaque);
}

void Animal::damage()
{
    this->vie -= 1;
}

bool Animal::alreadyFight(Animal * a)
{
    return this->getFlag() && a->getFlag();
}