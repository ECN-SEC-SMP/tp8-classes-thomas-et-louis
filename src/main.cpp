/**
 * @file main.cpp
 * @author Louis Vaillant & Thomas Verron
 * @brief 
 * @version 1.0
 * @date 2025-03-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

#include "Game.h"

int main(int argc, char const *argv[])
{
    std::cout << "Copiright ©️ 2021 - Louis Vaillant Thomas Verron - Tous droits réservés" << std::endl;

    srand(time(NULL));
    auto game = Game();
    game.playAllTurns(0);
    // game.playOneTurn();
    return 0;
}
