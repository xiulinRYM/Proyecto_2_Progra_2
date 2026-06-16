//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_SIMULATION_H
#define PROYECTO_2_PROGRA_2_SIMULATION_H


#include <string>
#include "Logger.h"
#include "ReportGenerator.h"
#include "../astronaut/Astronaut.h"
#include "../interface/GameUI.h"
#include "../world/SpaceStation.h"
#include"../events/Event.h"
#include "../events/Fire.h"
#include "../events/MeteorStrike.h"
#include "../events/OxygenLeak.h"
#include "../events/PowerFailure.h"

class Simulation {
public:
    Simulation(Astronaut* astronaut, SpaceStation* spacestation, int maxTurns = 10);
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
    SpaceStation* spaceStation;

    void triggerRandomEvent();
    void processTurn(int choice, GameUI& ui);
    bool checkDefeatCondition() const;
    bool checkVictoryCondition() const;
    void endSimulation(GameUI& ui);
    std::string caseNameModule();
};


#endif //PROYECTO_2_PROGRA_2_SIMULATION_H