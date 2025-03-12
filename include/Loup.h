#pragma once 

#include "Animal.h"

/**
 * @brief Class representing a Loup (wolf) animal
 * 
 */
class Loup : public Animal
{
public:
    /**
     * @brief Construct a new Loup object
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    Loup(int maxX, int maxY);

    /**
     * @brief Destroy the Loup object
     * 
     */
    virtual ~Loup() = default;

    /**
     * @brief Set the Attaque type for Loup
     * 
     */
    virtual void setAttaque();

    /**
     * @brief Move the Loup to a new position
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    virtual void deplace(int maxX, int maxY);
};

