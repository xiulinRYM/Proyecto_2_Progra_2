#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, Module*> stationMap_;
    int totalIntegrity_;
public:
    SpaceStation();
    ~SpaceStation();
    Module* getModule(const std::string &moduleName);
    void addModule(Module* module);
    void CalculateSystemStatus();
    std::map<std::string, Module*> getAllModules();
    [[nodiscard]] bool isOperational() const;
};