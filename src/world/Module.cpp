#include <utility>

#include "../../include/world/Module.h"

Module::Module(std::string name) : name_(std::move(name)), integrity_(100) {}

void Module::addConnection(Module* module) {
    connectedModules_.push_back(module);
}

std::vector<Module*> Module::getConnectedModules() {
    return connectedModules_;
}

int Module::getIntegrity() const {
    return integrity_;
}

void Module::setIntegrity(const int integrity) {
    integrity_ = integrity;
}

std::string Module::getName() const {
    return name_;
}

void Module::addItem(std::unique_ptr<Item> item) {
    items_.push_back(std::move(item));
}

std::vector<Item*> Module::getItems() const {
    std::vector<Item*> result;
    for (const auto& item : items_){
        result.push_back(item.get());
    }
    return result;
}

std::unique_ptr<Item> Module::extractItem(const Item* item) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if (it->get() == item) {
            std::unique_ptr<Item> extractedItem = std::move(*it);
            items_.erase(it);
            return extractedItem;
        }
    }
    return nullptr;
}

bool Module::isDestroyed() const {
    return integrity_ <= 0;
}

void Module::triggerEvent(Astronaut *a) const {
    for (Event* event : activeEvents_) {
        event->execute(*a);
    }
}
