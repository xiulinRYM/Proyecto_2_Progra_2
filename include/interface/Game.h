//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_GAME_H
#define PROYECTO_2_PROGRA_2_GAME_H


#include "../simulator/Simulation.h"
#include "GameUI.h"
#include "../astronaut/Astronaut.h"
#include"../world/SpaceStation.h"
#include <memory>

class Game {
public:
    Game(int maxTurns = 10);
    ~Game()=default;
    void init();
    void start();

private:
    std::unique_ptr<Astronaut> astronaut_;
    std::unique_ptr<Simulation> simulation_;
    std::unique_ptr<GameUI> ui_;
    std::unique_ptr<SpaceStation> spaceStation_;
    int maxTurns_;
};


#endif //PROYECTO_2_PROGRA_2_GAME_H