#pragma once

#include <string>

/**
 * @brief Class representing an Attaque (attack)
 * 
 */
class Attaque
{
private:
    int typeAttaque; // 0: pierre, 1: feuille, 2: ciseaux
public:
    /**
     * @brief Construct a new Attaque object
     * @details Attaque type set randomly
     */
    Attaque();

    /**
     * @brief Construct a new Attaque object
     * 
     * @param type (IN) Attaque type (0: pierre, 1: feuille, 2: ciseaux)
     */
    Attaque(int type);

    /**
     * @brief Destroy the Attaque object
     * 
     */
    ~Attaque() = default;

    /**
     * @brief Get the Attaque Type
     * 
     * @return int Attaque type (0: pierre, 1: feuille, 2: ciseaux)
     */
    int getTypeAttaque() const;

    /**
     * @brief Process Attaque
     * 
     * @param a Reference to another Attaque
     * @return true if win
     * @return false else
     */
    bool resoudreAttaque(Attaque &a) const;

    /**
     * @brief Get the Attaque Name 
     * 
     * @return std::string Attaque Name 
     */
    std::string getNomAttaque() const;
};