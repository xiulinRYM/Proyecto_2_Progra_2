//
// Created by danie on 11/6/2026.
//

#include "../../include/interface/GameUI.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"
#include<iostream>
void GameUI::showStatus(const Astronaut &astronaut, SpaceStation& spaceStation, int currentTurn, int maxTurns) {
    std::cout << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << " TURN " << currentTurn << " / " << maxTurns << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << " Station  : " << (spaceStation.isOperational() ? "OPERATIONAL" : "INOPERATIVE") << std::endl;
    if (astronaut.getCurrentModule()) {
        std::cout << " Module integrity: " << astronaut.getCurrentModule()->getIntegrity() << std::endl;
    }
    std::cout << " Location : " << (astronaut.getCurrentModule() ? astronaut.getCurrentModule()->getName() : "None") << std::endl;
    std::cout << " Health   : " << astronaut.getHealth() << std::endl;
    std::cout << " Oxygen   : " << astronaut.getOxygen() << std::endl;
    std::cout << " Energy   : " << astronaut.getEnergy() << std::endl;
    std::cout << "=======================================" << std::endl;
}


void GameUI::showMenu(const Astronaut& astronaut) {
    std::cout << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << " Select an option " << std::endl;
    std::cout << " 1. Move to another module" << std::endl;
    std::cout << " 2. Use an item  [" << astronaut.getInventory()->getSize() << " in inventory]" << std::endl;
    std::cout << " 3. Inspect current module" << std::endl;
    std::cout << " 4. Wait" << std::endl;
    std::cout << std::endl;
}


void GameUI::showMessage(const std::string &message) {
    std::cout<<message<<std::endl;
}

int GameUI::getPlayerInput() {
    int choice = 0;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 4) {
        std::cin.clear();
        choice = 4;
    }

    std::cin.ignore(1000, '\n');
    return choice;
}

void GameUI::showInventory(const Astronaut &astronaut) {
    if (astronaut.getInventory()->getSize()==0) {
        showMessage("Empty inventory");
    }else   for (int i = 0; i < astronaut.getInventory()->getSize(); i++) {
            std::cout<<" "<< i+1 <<". "<<astronaut.getInventory()->getItem(i)->getName()<<std::endl;
        }
}

int GameUI::getPlayerDecision()
{
    int choice = 0;
    std::cin >> choice;
    if (std::cin.fail())
    {
        std::cin.clear();
        choice = 0;
    }
    std::cin.ignore(1000, '\n');
    return choice;
}

void GameUI::showConnectedModules(const std::vector<Module*>& modules) {
    for (int i = 0; i < modules.size(); i++) {
        std::cout << " " << i+1 << ". " << modules[i]->getName() << std::endl;
    }
}

void GameUI::showModuleItems(const std::vector<Item*>& items) {
    for (int i = 0; i < items.size(); i++) {
        std::cout << " " << i+1 << ". " << items[i]->getName() << std::endl;
    }
}
