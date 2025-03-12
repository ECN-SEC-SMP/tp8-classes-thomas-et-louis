#pragma once

#include "Animal.h"

/**
 * @brief Class representing a Pierre (rock) animal
 * 
 */
class Pierre : public Animal
{
private:
    
public:
    /**
     * @brief Construct a new Pierre object
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    Pierre(int maxX, int maxY);

    /**
     * @brief Destroy the Pierre object
     * 
     */
    virtual ~Pierre() = default;

    /**
     * @brief Set the Attaque type for Pierre
     * 
     */
    virtual void setAttaque();

    /**
     * @brief Pierre does not move
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    virtual void deplace(int maxX, int maxY);
};
