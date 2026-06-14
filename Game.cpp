//
// Created by danie on 11/6/2026.
//

#include "Game.h"
#include <iostream>

Game::Game(int maxTurns) {
    this->maxTurns = maxTurns;
    this->astronaut = nullptr;
    this->simulation = nullptr;
    this->ui = nullptr;
}

Game::~Game() {
    delete astronaut;
    delete simulation;
    delete ui;
}

void Game::init() {
    astronaut = new Astronaut();
    ui = new GameUI();
    simulation = new Simulation(astronaut, maxTurns);
}

void Game::start() {
    if (astronaut == nullptr || simulation == nullptr || ui == nullptr) {
        std::cerr << "Error: Game not initialized. "
                  << "Call init() before start()." << std::endl;
        return;
    }
    simulation->runSimulation(*ui);
}