//
// Created by danie on 11/6/2026.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation(Astronaut *astronaut, int maxOP) {
    this->astronaut = astronaut;
    this->maxOP = maxOP;
    this->currentOp = 1;
    this->modulesVisited=1;
    this->isrunning = true;
    this->logger = new Logger("report.txt");
    this->reportGenerator = new ReportGenerator("finalReport.txt");
}
Simulation::~Simulation() {
    delete logger;
    delete reportGenerator;
}

void Simulation::processTurn(int choise) {
    std::string entry = "[TURN " + std::to_string(currentOp) + "] ";
    switch (choise) {
        case 1:
            entry += "Astronaut  move to " + astronaut->getCurrentModuleName();
            break;
        case 2:
            entry += "Astronaut used item";
            break;
        case 3:
            entry += "Astronaut inspected module: " + astronaut->getCurrentModuleName();
            break;
        case 4:
            entry += "Astronaut waited";
            break;
        default:
            entry += "Unknown action";
            break;
    }

    logger->writeEntry(entry);
}

bool Simulation::checkDefeatCondition() const {
    return !astronaut->isAlive();
}
bool Simulation::checkVictoryCondition() const {
    return currentOp >= maxOP && astronaut->isAlive();
}

void Simulation::endSimulation() {
    std::string result;
    if (astronaut->isAlive()) {
        result = "MISSION SUCCESS";
    } else {
        result = "MISSION FAILED";
    }
    int oxygen  = astronaut->getOxygen();
    int energy  = astronaut->getEnergy();
    int health  = astronaut->getHealth();
    reportGenerator->setMissionResult(result);
    reportGenerator->setFinalStats(oxygen, energy, health, modulesVisited);
    reportGenerator->generate(*logger);
    reportGenerator->saveToFile();
    logger->exportToFile();
}
void Simulation::runSimulation() {
    logger->writeHeader();
    ui.showMessage("Simulation started");
    while (isRunning && currentOP <= maxOP) {
        ui.showStatus(*astronaut, currentOP, maxOP);
        ui.showMenu();
        int choise = ui.getPlayerInput();
        processTurn(choise);
        if (checkDefeatCondition()) {
            logger->writeEntry("Turn " + std::to_string(currentOP) + " MISSION FAILED");
            ui.showMessage("MISSION FAILED. The simulation has been lost.");
            isRunning = false;
            endSimulation();
            return;
        }
    }
}

if (checkVictoryCondition()) {
    logger->writeEntry("Turn " + std::to_string(currentOP)
    + " MISSION SUCCESS");
    ui.showMessage("MISSION SUCCESS!");
    isRunning = false;
    endSimulation();
    return;
}
currentOP++;
 }
if (isRunning) {
    logger->writeEntry("=== MISSION ENDED - Maximum turns reached ===");
    ui.showMessage("Maximum turns reached. Mission ended.");
    endSimulation();
}
}


