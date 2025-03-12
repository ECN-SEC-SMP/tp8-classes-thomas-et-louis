#pragma once 

#include "Animal.h"

class Loup : public Animal
{
public:
    Loup(int maxX, int maxY);
    virtual ~Loup() = default;
    virtual void setAttaque();
    virtual void deplace(int maxX, int);
};

