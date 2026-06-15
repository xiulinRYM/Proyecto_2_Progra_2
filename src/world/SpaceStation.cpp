#include "../../include/world/SpaceStation.h"
#include <fstream>
#include <iostream>
#include <sstream>

SpaceStation::SpaceStation() : totalIntegrity_(100) {}

Module* SpaceStation::getModule(const std::string &moduleName) {
    if (stationMap_.contains(moduleName)) {
        return stationMap_[moduleName];
    }
    return nullptr;
}

std::map<std::string, Module*> SpaceStation::getAllModules() {
    return stationMap_;
}

bool SpaceStation::isOperational() const {
    if (stationMap_.empty()) {
        return false;
    }
    int x = 0;
    for (const auto& m : stationMap_) {
        if (m.second->isDestroyed()) {
            x += 1;
        }
    }
    if (x > stationMap_.size()/2) {
        return false;
    }
    return true;
}

void SpaceStation::addModule(Module* module) {
    if (module != nullptr) {
        stationMap_[module->getName()] = module;
    }
}

void SpaceStation::CalculateSystemStatus() {
    totalIntegrity_ = 0;
    for (const auto& m : stationMap_) {
        totalIntegrity_ += m.second->getIntegrity();
    }
}

void SpaceStation::loadModuleData(const std::string &file) {
    std::ifstream file_(file);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << file << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, moduleName;

        getline(s, type, ';');
        getline(s, moduleName, ';' );

        if (type == "MODULE") {
            auto* m = new Module(moduleName);
            stationMap_[moduleName] = m;
        }
    }
}

void SpaceStation::loadConnectionsData(const std::string &file) {
    std::ifstream file_(file);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << file << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, module1, module2;

        getline(s, type, ';');
        getline(s, module1, ';' );
        getline(s, module2, ';' );

        if (type == "CONNECTION") {
            Module* m1 = getModule(module1);
            if (Module* m2 = getModule(module2); m1 != nullptr && m2 != nullptr) {
                m1->addConnection(m2);
                m2->addConnection(m1);
            }
        }
    }
}

void SpaceStation::loadStationData(const std::string& file) {
    loadModuleData(file);
    loadConnectionsData(file);
}