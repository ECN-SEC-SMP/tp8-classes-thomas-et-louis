#include <algorithm>
#include <iostream>
#include <thread>

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
    for (int i = 0; i < _25percent/4; i++)
    {
        this->animals.push_back(new Lion(MAX_X, MAX_Y));
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
    std::cout << "Animals: " << this->animals.size() << std::endl << std::endl;
}

void Game::playOneTurn()
{
    for (auto &&animal : this->animals)
    {
        animal->deplace(MAX_X, MAX_Y);
    }
    for (auto &&animal : this->animals)
    {
        std::cout << animal->getNom() << " at " << animal->getX() << "," << animal->getY() << std::endl;
    }
    for (auto &&animal : this->animals)
    {
        Animal *other_animal = nullptr;
        while ((other_animal = getAnimalFromCoordinates(animal->getX(), animal->getY())) != nullptr && other_animal != animal)
        {
            bool win = animal->attaque(*other_animal);
            std::cout << animal->getNom() << " vs " << other_animal->getNom() << " -> " << (win ? "win" : "lose") << std::endl;
            std::cout << animal->getAttaque().getNomAttaque() << " vs " << other_animal->getAttaque().getNomAttaque() << std::endl;
            std::cout << animal->getNom() << " at " << animal->getX() << "," << animal->getY() << std::endl;
            std::cout << other_animal->getNom() << " at " << other_animal->getX() << "," << other_animal->getY() << std::endl;
            std::cout << std::endl;
            if (win)
            {
                this->animals.erase(std::find(this->animals.begin(), this->animals.end(), other_animal));
            }
            else
            {
                this->animals.erase(std::find(this->animals.begin(), this->animals.end(), animal));
                break;
            }
        }
        
    }
    for (auto &&animal : this->animals)
    {
        std::cout << animal->getNom() << " at " << animal->getX() << "," << animal->getY() << std::endl;
    }
    this->display();
}

void Game::playAllTurns(int wait_time)
{
    while (this->animals.size() > 1)
    {
        this->playOneTurn();
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    }
    std::cout << "Winner: " << this->animals[0]->getNom() << std::endl;
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