#include "Game.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    auto game = Game();
    game.playAllTurns(0);
    // game.playOneTurn();
    return 0;
}
