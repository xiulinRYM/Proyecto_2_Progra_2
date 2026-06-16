#include "../../include/world/SpaceStation.h"

SpaceStation::SpaceStation() : totalIntegrity_(100) {}

SpaceStation::~SpaceStation() {
    stationMap_.clear();
}

Module* SpaceStation::getModule(const std::string &moduleName) {
    if (stationMap_.contains(moduleName)) {
        return stationMap_[moduleName].get();
    }
    return nullptr;
}

const std::map<std::string, std::unique_ptr<Module>>& SpaceStation::getAllModules() const {
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

void SpaceStation::addModule(std::unique_ptr<Module> module) {
    if (module != nullptr) {
        stationMap_[module->getName()] = std::move(module);
    }
}

void SpaceStation::CalculateSystemStatus() {
    totalIntegrity_ = 0;
    for (const auto& m : stationMap_) {
        totalIntegrity_ += m.second->getIntegrity();
    }
}