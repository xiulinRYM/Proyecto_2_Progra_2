cmake_minimum_required(VERSION 3.20)
project(Proyecto_2_Progra_2)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Proyecto_2_Progra_2
        main.cpp

        # Astronaut
        src/astronaut/Astronaut.cpp
        src/astronaut/Inventory.cpp

        # Items
        src/astronaut/items/EnergyCell.cpp
        src/astronaut/items/OxygenTank.cpp
        src/astronaut/items/RepairKit.cpp
        src/astronaut/items/RepairTool.cpp

        # Events
        src/events/Fire.cpp
        src/events/MeteorStrike.cpp
        src/events/PowerFailure.cpp
        src/events/OxygenLeak.cpp

        # World
        src/world/Module.cpp
        src/world/SpaceStation.cpp

        # Simulator
        src/simulator/Logger.cpp
        src/simulator/ReportGenerator.cpp
        src/simulator/Simulation.cpp

        # Interface
        src/interface/Game.cpp
        src/interface/GameUI.cpp
        include/world/StationLoader.h
        src/world/StationLoader.cpp
)