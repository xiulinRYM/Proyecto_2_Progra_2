//
// Created by danie on 11/6/2026.
//

#include "../../include/interface/GameUI.h"
#include "../../include/astronaut/Astronaut.h"
#include<iostream>

void GameUI::showStatus(const Astronaut &astronaut, int currentTurn, int maxTurns) const {
    std::cout<<std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << " TURN " << currentTurn << " / " << maxTurns << std::endl;
    std::cout << "=======================================" << std::endl;
    std::cout << " Location : " << astronaut.getCurrentModule() << std::endl;
    std::cout << " Health : " << astronaut.getHealth() << std::endl;
    std::cout << " Oxygen : " << astronaut.getOxygen() << std::endl;
    std::cout << " Energy : " << astronaut.getEnergy() << std::endl;
    std::cout << "=======================================" << std::endl;

}
void GameUI::showMenu() const {
    std::cout<<std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << " Welcome " << std::endl;
    std::cout << " Select an option " << std::endl;
    std::cout << " 1. Move to another module" << std::endl;
    std::cout << " 2. Use an item" << std::endl;
    std::cout << " 3. Inspect current module" << std::endl;
    std::cout << " 4. Wait" << std::endl;
    std::cout << std::endl;
}

void GameUI::showMessage(const std::string &message) const {
    std::cout<<message<<std::endl;
}

int GameUI::getPlayerInput() const {
    int choice = 0;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 4) {
        std::cin.clear();
        choice = 4;
    }

    std::cin.ignore(1000, '\n');
    return choice;
}