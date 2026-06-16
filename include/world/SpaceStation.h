#pragma once
#include "Module.h"
#include <string>
#include <map>

class SpaceStation {
    std::map<std::string, Module*> stationMap_;
    int totalIntegrity_;
public:
    SpaceStation();
    void loadStationData(const std::string& file);
    void loadModuleData(const std::string& file);
    void loadConnectionsData(const std::string& file);
    void loadItemsData(const std::string& file);
    Module* getModule(const std::string &moduleName);
    void addModule(Module* module);
    void CalculateSystemStatus();
    std::map<std::string, Module*> getAllModules();
    [[nodiscard]] bool isOperational() const;
};