#pragma once

#include <string>
#include <stdlib.h>
#include <time.h>

#include "Attaque.h"

/**
 * @brief Base class representing an Animal
 * 
 */
class Animal
{
protected:
    std::string nom;
    int x;
    int y;
    bool vivant;
    int vie;
    int flag;
    Attaque typeAttaque;
public:
    /**
     * @brief Construct a new Animal object
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    Animal(int maxX, int maxY);

    /**
     * @brief Construct a new Animal object with specific coordinates
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     * @param x X coordinate
     * @param y Y coordinate
     */
    Animal(int maxX, int maxY, int x, int y);

    /**
     * @brief Destroy the Animal object
     * 
     */
    virtual ~Animal() = default;

    /**
     * @brief Get the name of the Animal
     * 
     * @return std::string Name of the Animal
     */
    std::string getNom() const;

    /**
     * @brief Get the X coordinate of the Animal
     * 
     * @return int X coordinate
     */
    int getX() const;

    /**
     * @brief Get the Y coordinate of the Animal
     * 
     * @return int Y coordinate
     */
    int getY() const;


    int getLife() const;

    int getFlag() const;

    void setFlag();

    void resetFlag();
    /**
     * @brief Check if the Animal is alive
     * 
     * @return true if alive
     * @return false if not alive
     */
    bool getVivant() const;

    /**
     * @brief Get the Attaque type of the Animal
     * 
     * @return Attaque Attaque type
     */
    Attaque getAttaque() const;

    /**
     * @brief Set the alive status of the Animal
     * 
     * @param v Alive status
     */
    void setVivant(bool v);

    /**
     * @brief Process an attack on another Animal
     * 
     * @param a Reference to the other Animal
     * @return true if the attack is successful
     * @return false if the attack is not successful
     */
    bool attaque(Animal &a);

    void damage();

    bool alreadyFight(Animal * a);

    bool sameAnimal(Animal * a);

    /**
     * @brief Set the Attaque type for the Animal
     * 
     */
    virtual void setAttaque() = 0; // virtuelle pure

    /**
     * @brief Move the Animal to a new position
     * 
     * @param maxX Maximum X coordinate
     * @param maxY Maximum Y coordinate
     */
    virtual void deplace(int maxX, int maxY) = 0; // virtuelle pure
};
