//
// Created by danie on 11/6/2026.
//

#include "../../include/interface/Game.h"
#include <iostream>


Game::Game(int maxTurns) : maxTurns_(maxTurns)
{}

void Game::init() {
    astronaut_ = std::make_unique<Astronaut>();
    spaceStation_ = std::make_unique<SpaceStation>();
    ui_ = std::make_unique<GameUI>();
    simulation_ = std::make_unique<Simulation>(astronaut_.get(), spaceStation_.get(), maxTurns_);
}

void Game::start() {
    if (!astronaut_ || !simulation_ || !ui_) {
        std::cerr << "Error: Game not initialized. "
                  << "Call init() before start()." << std::endl;
        return;
    }
    simulation_->runSimulation(*ui_);
}