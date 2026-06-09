#pragma once
#include "Module.h"
#include <string>

class SpaceStation {
    map<std::string, Module*> stationMap_;
    int totalOxygen_;
    int totalEnergy_;
public:
    void loadStationData(std::string file);
    Module* getModule(std::string moduleName);
    void CalculateSystemStatus();
    map<std::string, Module*> getAllModules();
    bool isOperational();
};