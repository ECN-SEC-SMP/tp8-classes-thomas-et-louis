#include "Animal.h"

class Ours : public Animal
{
public:
    Ours(int maxX, int maxY);
    virtual ~Ours() = default;
    virtual void setAttaque();
    virtual void deplace(int maxX, int maxY);
};