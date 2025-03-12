#pragma once

#include "Animal.h"

class Lion : public Animal
{
public:
    Lion(int maxX, int maxY);
    virtual ~Lion() = default;
    virtual void setAttaque();
    virtual void deplace(int maxX, int maxY);
};