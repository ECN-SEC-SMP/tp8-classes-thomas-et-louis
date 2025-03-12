#pragma once

#include "Animal.h"

class Pierre : public Animal
{
private:
    
public:
    Pierre(int maxX, int maxY);
    virtual ~Pierre() = default;
    virtual void setAttaque();
    virtual void deplace(int maxX, int maxY);
};
