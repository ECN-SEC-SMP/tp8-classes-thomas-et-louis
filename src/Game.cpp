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
                    std::cout << "| " << animal->getNom() << " ";
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
        if(getNumberOfSameAnimal(animal))
        {
            for(int i = 0; i < getNumberOfSameAnimal(animal); i++)
            {
                if(animal->getNom() == "🐻")
                {
                    this->animals.push_back(new Ours(MAX_X, MAX_Y));
                }
                if(animal->getNom() == "🐺")
                {
                    this->animals.push_back(new Loup(MAX_X, MAX_Y));
                }
                if(animal->getNom() == "🪨 ")
                {
                    this->animals.push_back(new Pierre(MAX_X, MAX_Y));
                }
                if(animal->getNom() == "🦁")
                {
                    this->animals.push_back(new Lion(MAX_X, MAX_Y));
                }
            }
        }
        Animal *other_animal = nullptr;
        while ((other_animal = getAnimalFromCoordinates(animal->getX(), animal->getY())) != nullptr && other_animal != animal && !animal->alreadyFight(other_animal) && !animal->sameAnimal(other_animal))
        {
            animal->setFlag();
            other_animal->setFlag();
            bool win = animal->attaque(*other_animal);
            std::cout << animal->getNom() << " vs " << other_animal->getNom() << " -> " << animal->getNom() << (win ? " win" : " lose") << std::endl;
            std::cout << (win ? other_animal->getNom() : animal->getNom()) << " " << (win ? other_animal->getLife() -1 : animal->getLife() -1 ) << " life" << std::endl;
            std::cout << animal->getAttaque().getNomAttaque() << " vs " << other_animal->getAttaque().getNomAttaque() << std::endl;
            std::cout << std::endl;
            if (win)
            {
                other_animal->damage();
                if(!other_animal->getLife())
                {
                    this->animals.erase(std::find(this->animals.begin(), this->animals.end(), other_animal));
                    break;
                }
            }
            else
            {
                animal->damage();
                if(!animal->getLife())
                {
                    this->animals.erase(std::find(this->animals.begin(), this->animals.end(), animal));
                    break;
                }
            }      
        }
        for (auto &&animal : this->animals)
        {
            animal->resetFlag();
        }

    }
    
    this->display();
}

void Game::playAllTurns(int wait_time)
{
    while (!gameFinished() && this->animals.size() < 7*MAX_X )
    {
        this->playOneTurn();
        std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    }
    std::cout << "Winner: " << maxPopulation() << std::endl;
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


int Game::getNumberOfSameAnimal(Animal * a)
{
    int nb = 0;
    for (auto &&other_animal : animals)
    {
        if(a->sameAnimal(other_animal))
        {
            nb += 1;
        }
    }
    return nb;
    
}

bool Game::gameFinished()
{
    bool flag = true;
    Animal * a = this->animals[0];
    for (auto &&animal : animals)
    {
        if(a->getNom() != animal->getNom()) flag = false;
    }
    return flag;
}

std::string Game::maxPopulation()
{
    int Ours = 0;
    int Loup = 0;
    int Pierre = 0;
    int Lion = 0;
    for (auto &&animal : animals)
    {
        if(animal->getNom() == "🐻") Ours += 1;
        if(animal->getNom() == "🐺") Loup += 1;
        if(animal->getNom() == "🪨 ") Pierre += 1;
        if(animal->getNom() == "🦁") Lion += 1;
    }
    if(Ours == std::max({Ours, Loup, Pierre, Lion})) return "🐻";
    if(Loup == std::max({Ours, Loup, Pierre, Lion})) return "🐺";
    if(Pierre == std::max({Ours, Loup, Pierre, Lion})) return "🪨 ";
    if(Lion == std::max({Ours, Loup, Pierre, Lion})) return "🦁";
    else return nullptr;
}