#include "../../include/world/SpaceStation.h"

Module* SpaceStation::getModule(std::string moduleName) {
    return modules_[moduleName];
}

std::map<std::string, Module*> SpaceStation::getAllModules() {
    return modules_;
}

bool SpaceStation::isOperational() {
    if (modules_.empty()) {
        return false;
    }
    int x = 0;
    for (const auto& m : modules_) {
        if (m.second->isDestroyed()) {
            x += 1;
        }
    }
    if (x > modules_.size()/2) {
        return false;
    }
    return true;
}

void SpaceStation::addModule(Module* module) {
    modules_.push_back(module);
}

void SpaceStation::CalculateSystemStatus() {
    totalOxygen_ = 0;
    totalEnergy_ = 0;
    for (const auto& m : modules_) {
        for (const auto& item : m.second->getItems()) {
            if (item->getType() == "Oxygen") {
                totalOxygen_ += item->getQuantity();
            } else if (item->getType() == "Energy") {
                totalEnergy_ += item->getQuantity();
            }
        }
    }
}

void SpaceStation::loadStationData(std::string file) {
 //Falta
}