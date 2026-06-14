#include "../../include/world/Module.h"

Module::Module(const std::string &name) : name_(name), integrity_(100) {}

void Module::addConnection(Module* module) {
    connectedModules_.push_back(module);
}

std::vector<Module*> Module::getConnectedModules() {
    return connectedModules_;
}

int Module::getIntegrity() const {
    return integrity_;
}

void Module::setIntegrity(int integrity) {
    integrity_ = integrity;
}

std::string Module::getName() {
    return name_;
}

void Module::addItem(Item* item) {
    items_.push_back(item);
}

std::vector<Item*> Module::getItems() {
    return items_;
}

void Module::removeItem(Item* item) {
    std::erase(items_, item);
}

bool Module::isDestroyed() const {
    return integrity_ <= 0;
}

void triggerEvent(Event* event);
