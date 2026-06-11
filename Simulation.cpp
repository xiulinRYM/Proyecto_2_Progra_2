//
// Created by danie on 11/6/2026.
//

#include "Simulation.h"
#include <iostream>

Simulation::Simulation(Astronaut* astronaut, int maxTurns) {
    this->astronaut = astronaut;
    this->maxTurns = maxTurns;
    this->currentTurn = 1;
    this->modulesVisited = 1;
    this->isRunning = true;
    this->logger = new Logger("report.txt");
    this->reportGenerator = new ReportGenerator("finalReport.txt");
}

Simulation::~Simulation() {
    delete logger;
    delete reportGenerator;
}

void Simulation::processTurn(int choice, GameUI& ui) {
    std::string entry = "[TURN " + std::to_string(currentTurn) + "] ";

    switch (choice) {
        case 1:
            entry += "Astronaut moved to " + astronaut->getCurrentModuleName();
            break;
        case 2:
            entry += "Astronaut used an item";
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
    return currentTurn >= maxTurns && astronaut->isAlive();
}

void Simulation::endSimulation(GameUI& ui) {
    std::string result;
    if (astronaut->isAlive()) {
        result = "MISSION SUCCESS";
    } else {
        result = "MISSION FAILED";
    }

    reportGenerator->setMissionResult(result);
    reportGenerator->setFinalStats(
        astronaut->getOxygen(),
        astronaut->getEnergy(),
        astronaut->getHealth(),
        modulesVisited
    );
    reportGenerator->generate(*logger);
    reportGenerator->saveToFile();
    logger->exportToFile();
}

void Simulation::runSimulation(GameUI& ui) {
    logger->writeHeader();
    ui.showMessage("=== SIMULATION STARTED ===");

    while (isRunning && currentTurn <= maxTurns) {
        ui.showStatus(*astronaut, currentTurn, maxTurns);
        ui.showMenu();

        int choice = ui.getPlayerInput();
        processTurn(choice, ui);

        if (checkDefeatCondition()) {
            logger->writeEntry("[TURN " + std::to_string(currentTurn) + "] MISSION FAILED");
            ui.showMessage("MISSION FAILED. The astronaut did not survive.");
            isRunning = false;
            endSimulation(ui);
            return;
        }

        if (checkVictoryCondition()) {
            logger->writeEntry("[TURN " + std::to_string(currentTurn) + "] MISSION SUCCESS");
            ui.showMessage("MISSION SUCCESS! The astronaut survived.");
            isRunning = false;
            endSimulation(ui);
            return;
        }

        currentTurn++;
    }

    if (isRunning) {
        logger->writeEntry("=== MISSION ENDED - Maximum turns reached ===");
        ui.showMessage("Maximum turns reached. Mission ended.");
        endSimulation(ui);
    }
}


