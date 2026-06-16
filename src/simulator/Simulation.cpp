//
// Created by danie on 11/6/2026.
//

#include "../../include/simulator/Simulation.h"
#include <iostream>
#include "../../include/world/Module.h"
#include <cstdlib>
#include <ctime>

Simulation::Simulation(Astronaut* astronaut, SpaceStation* spaceStation, int maxTurns) {
    this->astronaut = astronaut;
    this->spaceStation = spaceStation;
    this->maxTurns = maxTurns;
    this->currentTurn = 1;
    this->modulesVisited = 1;
    this->isRunning = true;
    this->logger = new Logger("report.txt");
    this->reportGenerator = new ReportGenerator("finalReport.txt");
    srand(time(nullptr));
}

Simulation::~Simulation() {
    delete logger;
    delete reportGenerator;
}

void Simulation::processTurn(int choice, GameUI& ui) {
    std::string entry = "[TURN " + std::to_string(currentTurn) + "] ";

    switch (choice) {
        case 1:
            if (astronaut->getCurrentModule() == nullptr) {
                ui.showMessage("No current module.");
            } else {
                std::vector<Module*> connected = astronaut->getCurrentModule()->getConnectedModules();
                if (connected.empty()) {
                    ui.showMessage("No connected modules available.");
                    break;
                }
                for (int i = 0; i < connected.size(); i++) {
                    std::cout << " " << i+1 << ". " << connected[i]->getName() << std::endl;
                }
                int op;
                std::cout << "Select a module" << std::endl;
                std::cin >> op;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    ui.showMessage("Invalid input.");
                    break;
                }
                if (op < 1 || op > (int)connected.size()) {
                    ui.showMessage("Invalid selection. Staying in current module.");
                    break;
                }
                astronaut->move(connected[op - 1]);
                modulesVisited++;
            }
            entry += "Astronaut moved to " + caseNameModule();
            break;

        case 2:
            if (astronaut->getInventory()->getSize() > 0) {
                ui.showInventory(*astronaut);
                std::cout << "Select item: ";
                int op;
                std::cin >> op;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    ui.showMessage("Invalid input.");
                    break;
                }
                if (op >= 1 && op <= (int)astronaut->getInventory()->getSize()) {
                    std::string itemName = astronaut->getInventory()->getItem(op-1)->getName();
                    astronaut->useItem(op-1);
                    entry += "Astronaut used " + itemName;
                } else {
                    ui.showMessage("Invalid selection.");
                }
            } else {
                ui.showMessage("Inventory is empty.");
            }
            break;

        case 3:
            if (astronaut->getCurrentModule() == nullptr) {
                ui.showMessage("No current module.");
            } else {
                std::cout << astronaut->getCurrentModule()->getName() << std::endl;
                std::cout << astronaut->getCurrentModule()->getIntegrity() << std::endl;
                std::vector<Item*> items = astronaut->getCurrentModule()->getItems();
                for (int i = 0; i < items.size(); i++) {
                    std::cout << " " << i+1 << ". " << items[i]->getName() << std::endl;
                }
                int op;
                std::cout << "Select item number to take (0 to skip): " << std::endl;
                std::cin >> op;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    ui.showMessage("Invalid input.");
                    break;
                }
                if (op >= 1 && op <= (int)items.size()) {
                    std::string takenName = items[op-1]->getName();
                    auto extracted = astronaut->getCurrentModule()->extractItem(items[op-1]);
                    if (extracted) {
                        astronaut->takeItem(std::move(extracted));
                        entry += "Astronaut took " + takenName;
                    }
                }
            }
            entry += "Astronaut inspected module: " + caseNameModule();
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

std::string Simulation::caseNameModule() {
    return astronaut->getCurrentModule() ? astronaut->getCurrentModule()->getName() : "UNKNOWN";
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

    while (isRunning && currentTurn <= maxTurns) {
        ui.showStatus(*astronaut, *spaceStation, currentTurn, maxTurns);
        ui.showMenu(*astronaut);

        int choice = ui.getPlayerInput();
        processTurn(choice, ui);
        for (const auto& [name, module] : spaceStation->getAllModules()) {
            auto descs = module->triggerEvent(astronaut);
            for (const auto& d : descs) {
                ui.showMessage("WARNING active event: " + d);
            }
        }
        triggerRandomEvent(ui);

        if (astronaut->getCurrentModule() != nullptr &&
            astronaut->getCurrentModule()->isDestroyed()) {
            ui.showMessage("WARNING: Module destroyed! Evacuating...");
            astronaut->setCurrentModule(spaceStation->getStartModule());
            logger->writeEntry("Module destroyed. Astronaut evacuated.");
        }

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

void Simulation::triggerRandomEvent(GameUI& ui) {
    int act = rand() % 100 + 1;
    if (act > 25) return;
    std::unique_ptr<Event> evento;
    std::string desc;
    int eventType = rand() % 4;
    switch (eventType) {
    case 0: { evento = std::make_unique<MeteorStrike>(); break; }
    case 1: { evento = std::make_unique<Fire>(); break; }
    case 2: { evento = std::make_unique<OxygenLeak>(); break; }
    case 3: { evento = std::make_unique<PowerFailure>(); break; }
    default: break;
    }
    if (evento) {
        evento->execute(*astronaut);
        desc = evento->getDescription();
    }

    if (desc.empty()) return;

    logger->writeEntry("EVENT: " + desc);
    ui.showMessage("==================");
    ui.showMessage("WARNING: " + desc);
    ui.showMessage("==================");
    ui.showMessage("Repair module manually? Costs 5 HP. (1=Yes, 0=No)");

    int rep;
    std::cin >> rep;
    if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); rep = 0; }

    if (rep == 1 && astronaut->getCurrentModule() != nullptr) {
        astronaut->getCurrentModule()->setIntegrity(astronaut->getCurrentModule()->getIntegrity() + 10);
        astronaut->applyDamage(5);
        ui.showMessage("Module repaired. You lost 5 HP.");
        logger->writeEntry("Player repaired module manually.");
    } else {
        ui.showMessage("Repair skipped.");
        if (astronaut->getCurrentModule() != nullptr)
        {
            astronaut->getCurrentModule()->addEvent(std::move(evento));
        }
        logger->writeEntry("EVENT persist in module: " + desc);
    }

    if (astronaut->getCurrentModule() != nullptr) {
        Module* mod = astronaut->getCurrentModule();
        int i = 0;
        while (i < mod->getActiveEventCount()) {
            ui.showMessage("Active event: " + mod->getActiveEventDescription(i));
            ui.showMessage("Repair? Costs 5 HP. (1=Yes, 2=Skip all, 0=Skip)");
            int r;
            std::cin >> r;
            if (std::cin.fail()) { std::cin.clear(); std::cin.ignore(1000, '\n'); r = 0; }
            if (r == 1) {
                mod->resolveEvent(i);
                astronaut->applyDamage(5);
                ui.showMessage("Event resolved. You lost 5 HP.");
                logger->writeEntry("Player resolved active event.");
            } else if (r == 2) {
                break;
            } else {
                i++;
            }
        }
    }
}