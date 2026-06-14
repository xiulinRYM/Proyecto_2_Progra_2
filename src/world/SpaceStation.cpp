#include "../../include/world/SpaceStation.h"
#include "../../include/astronaut/items/Item.h"

SpaceStation::SpaceStation() : totalOxygen_(100), totalEnergy_(100) {}

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
    totalOxygen_ = 0;
    totalEnergy_ = 0;
    for (const auto& m : stationMap_) {
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