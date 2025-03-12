#include "Game.h"

Game::Game()
{
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            this->cells[i][j] = nullptr;
        }
    }
}

void Game::display()
{

}

void Game::playOneTurn()
{

}

void Game::playAllTurns()
{

}
