#pragma once

#include "Animal.h"

/**
 * @brief Class representing an Ours (bear) animal
 * 
 */
class Ours : public Animal
{
public:
    /**
     * @brief Construct a new Ours object
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    Ours(int maxX, int maxY);

    /**
     * @brief Destroy the Ours object
     * 
     */
    virtual ~Ours() = default;

    /**
     * @brief Set the Attaque type for Ours
     * 
     */
    virtual void setAttaque();

    /**
     * @brief Move the Ours to a new position
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    virtual void deplace(int maxX, int maxY);
};