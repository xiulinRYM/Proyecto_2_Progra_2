#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, Module*> stationMap_;
    int totalOxygen_;
    int totalEnergy_;
public:
    SpaceStation();
    void loadStationData(std::string file);
    Module* getModule(const std::string &moduleName);
    void addModule(Module* module);
    void CalculateSystemStatus();
    std::map<std::string, Module*> getAllModules();
    bool isOperational() const;
};