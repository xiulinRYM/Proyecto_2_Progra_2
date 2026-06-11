//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_GAME_H
#define PROYECTO_2_PROGRA_2_GAME_H


#include "Simulation.h"
#include "GameUI.h"
#include "Astronaut.h"

class Game {
public:
    Game(int maxTurns = 10);
    ~Game();
    void init();
    void start();

private:
    Astronaut* astronaut;
    Simulation* simulation;
    GameUI* ui;
    int maxTurns;
};


#endif //PROYECTO_2_PROGRA_2_GAME_H