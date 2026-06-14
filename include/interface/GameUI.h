//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_GAMEUI_H
#define PROYECTO_2_PROGRA_2_GAMEUI_H


#include <string>
#include "../astronaut/Astronaut.h"

class GameUI {
public:
    void showStatus(const Astronaut& astronaut, int currentTurn,int maxTurns) const;
    void showMenu() const;
    void showMessage(const std::string& message) const;
    int getPlayerInput() const;
};


#endif //PROYECTO_2_PROGRA_2_GAMEUI_H