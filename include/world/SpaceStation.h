#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, Module*> stationMap_;
    int totalOxygen_;
    int totalEnergy_;
public:
    void loadStationData(std::string file);
    Module* getModule(std::string moduleName);
    void CalculateSystemStatus();
    std::map<std::string, Module*> getAllModules();
    bool isOperational();
};