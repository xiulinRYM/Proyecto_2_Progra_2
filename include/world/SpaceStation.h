#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, std::unique_ptr<Module>> stationMap_;
    int totalIntegrity_;
public:
    SpaceStation();
    ~SpaceStation();
    Module* getModule(const std::string &moduleName);
    void addModule(std::unique_ptr<Module> module);
    void CalculateSystemStatus();
    [[nodiscard]] const std::map<std::string, std::unique_ptr<Module>>& getAllModules() const;
    [[nodiscard]] bool isOperational() const;
};