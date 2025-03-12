#pragma once

#include <vector>

#include "Animal.h"

#define MAX_X 10
#define MAX_Y 10

/**
 * @brief Class representing the Game
 * 
 */
class Game
{
private:
    std::vector<Animal *> animals;
    Animal * cells[MAX_X][MAX_Y];
public:
    /**
     * @brief Construct a new Game object
     * 
     */
    Game();

    /**
     * @brief Destroy the Game object
     * 
     */
    ~Game() = default;

    /**
     * @brief Display the game board
     * 
     */
    void display();

    /**
     * @brief Play one turn of the game
     * 
     */
    void playOneTurn();

    /**
     * @brief Play all turns of the game
     * 
     */
    void playAllTurns(int wait_time);

    /**
     * @brief Get the Animal From Coordinates object
     * 
     * @param x X coordinate
     * @param y Y coordinate
     * @return Animal* Pointer to the animal at the given coordinates, or nullptr if no animal is present
     */
    Animal * getAnimalFromCoordinates(int x, int y);
};