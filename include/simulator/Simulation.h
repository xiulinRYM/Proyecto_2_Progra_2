//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_SIMULATION_H
#define PROYECTO_2_PROGRA_2_SIMULATION_H


#include <string>
#include "Logger.h"
#include "ReportGenerator.h"
#include "Astronaut.h"
#include "../interface/GameUI.h"

class Simulation {
public:
    Simulation(Astronaut* astronaut, int maxTurns = 10);
    ~Simulation();
    void runSimulation(GameUI& ui);

private:
    Astronaut* astronaut;
    int maxTurns;
    int currentTurn;
    int modulesVisited;
    bool isRunning;
    Logger* logger;
    ReportGenerator* reportGenerator;

    void processTurn(int choice, GameUI& ui);
    bool checkDefeatCondition() const;
    bool checkVictoryCondition() const;
    void endSimulation(GameUI& ui);
};


#endif //PROYECTO_2_PROGRA_2_SIMULATION_H