#pragma once

#include <vector>

#include "Animal.h"

#define MAX_X 10
#define MAX_Y 10

class Game
{
private:
    std::vector<Animal *> animals;
public:
    Game();
    ~Game() = default;
    void display();
    void playOneTurn();
    void playAllTurns();
    Animal * getAnimalFromCoordinates(int x, int y);
};