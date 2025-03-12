#pragma once

#include <vector>

#include "Animal.h"

#define MAX_X 10
#define MAX_Y 10

class Game
{
private:
    Animal * cells[MAX_X][MAX_Y];
public:
    Game();
    ~Game();
    void display();
    void playOneTurn();
    void playAllTurns();
};