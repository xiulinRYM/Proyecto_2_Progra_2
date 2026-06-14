#include <iostream>
#include "include/interface/Game.h"

int main()
{
    Game game(10);
    game.init();
    game.start();
    return 0;
}