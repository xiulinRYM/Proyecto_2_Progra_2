#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, std::unique_ptr<Module>> stationMap_;
    int totalIntegrity_;
    Module* startModule_ = nullptr;

public:
    SpaceStation();
    ~SpaceStation();
    Module* getModule(const std::string &moduleName);
    void addModule(std::unique_ptr<Module> module);
    void CalculateSystemStatus();
    [[nodiscard]] const std::map<std::string, std::unique_ptr<Module>>& getAllModules() const;
    [[nodiscard]] bool isOperational() const;
    void setStartModule(Module* module);
    [[nodiscard]] Module* getStartModule() const;
};