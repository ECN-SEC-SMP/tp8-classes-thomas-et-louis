#include <iostream>

#include "Game.h"
#include "Lion.h"
#include "Ours.h"
#include "Loup.h"
#include "Pierre.h"

Game::Game()
{
    int _25percent = MAX_X * MAX_Y / 4;
    for (int i = 0; i < _25percent/4; i++)
    {
        this->animals.push_back(new Lion(MAX_X, MAX_Y));
    }
    for (int i = 0; i < _25percent/4; i++)
    {
        this->animals.push_back(new Ours(MAX_X, MAX_Y));
    }
    for (int i = 0; i < _25percent/4; i++)
    {
        this->animals.push_back(new Loup(MAX_X, MAX_Y));
    }
    for (int i = 0; i < _25percent/4; i++)
    {
        this->animals.push_back(new Pierre(MAX_X, MAX_Y));
    }
    this->display();
}

void Game::display()
{
    for (int i = 0; i < MAX_Y*2+1; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < MAX_X; j++)
            {
                std::cout << "|----";
            }
            std::cout << "|" << std::endl;
        }
        else
        {
            for (int j = 0; j < MAX_X; j++)
            {
                auto animal = this->getAnimalFromCoordinates(j, i/2);
                if (animal != nullptr)
                {
                    std::cout << "| " << animal->getNom() << "  ";
                }
                else
                {
                    std::cout << "|    ";
                }
            }
            std::cout << "|" << std::endl;
        }
    }
}

void Game::playOneTurn()
{

}

void Game::playAllTurns()
{

}


Animal * Game::getAnimalFromCoordinates(int x, int y)
{
    for (auto &&i : this->animals)
    {
        if(i->getX() == x && i->getY() == y)
        {
            return i;
        }
    }
    return nullptr;
}