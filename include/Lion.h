#pragma once

#include "Animal.h"

/**
 * @brief Class representing a Lion animal
 * 
 */
class Lion : public Animal
{
public:
    /**
     * @brief Construct a new Lion object
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    Lion(int maxX, int maxY);

    /**
     * @brief Destroy the Lion object
     * 
     */
    virtual ~Lion() = default;

    /**
     * @brief Set the Attaque type for Lion
     * 
     */
    virtual void setAttaque();

    /**
     * @brief Move the Lion to a new position
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    virtual void deplace(int maxX, int maxY);
};