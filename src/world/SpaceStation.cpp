#include "../../include/world/SpaceStation.h"

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

void SpaceStation::loadStationData(std::string file) {
}