//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_SIMULATION_H
#define PROYECTO_2_PROGRA_2_SIMULATION_H


#include <string>
#include "Logger.h"
#include "ReportGenerator.h"
#include "Astronaut.h"
#include "GameUI.h"

class Simulation {
public:
    Simulation(Astronaut* astronaut, int maxOP=10);
    ~Simulation();
    void runSimulatiom(GameUI* gameUI);

private:
    Astronaut* astronaut;
    int maxOP;
    Logger* logger;
    ReportGenerator* reportGenerator;
    bool isrunning;
    int currentOp;
    int modulesVisited;
    void processTurn(int choise);
    bool checkDefeatCondition()const ;
    bool checkVictoryCondition() const;
    void endSimulation();

};


#endif //PROYECTO_2_PROGRA_2_SIMULATION_H