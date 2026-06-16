//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_GAMEUI_H
#define PROYECTO_2_PROGRA_2_GAMEUI_H


#include <string>
#include "../astronaut/Astronaut.h"
#include "../world/SpaceStation.h"

class GameUI {
public:
    void showStatus(const Astronaut& astronaut, SpaceStation& spaceStation, int currentTurn,int maxTurns) ;
    void showMenu(const Astronaut& astronaut ) ;
    void showMessage(const std::string& message) ;
    void showInventory(const Astronaut& astronaut) ;
    [[nodiscard]] int getPlayerInput() ;
    [[nodiscard]] int getPlayerDecision() ;
    void showConnectedModules(const std::vector<Module*>& modules) ;
    void showModuleItems(const std::vector<Item*>& items) ;
};


#endif //PROYECTO_2_PROGRA_2_GAMEUI_H