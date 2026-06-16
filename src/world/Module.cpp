#include <utility>

#include "../../include/world/Module.h"

Module::Module(std::string name) : name_(std::move(name)), integrity_(100) {}

void Module::addConnection(Module* module) {
    connectedModules_.push_back(module);
}

std::vector<Module*> Module::getConnectedModules() const {
    std::vector<Module*> result;
    for (const auto& module : connectedModules_) {
        if (module && !module->isDestroyed()) {
            result.push_back(module);
        }
    }
    return result;
}

int Module::getIntegrity() const {
    return integrity_;
}

void Module::setIntegrity(const int integrity) {
    if (integrity < 0) {
        integrity_ = 0;
    } else if (integrity > 100) {
        integrity_ = 100;
    } else
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

std::vector<std::string> Module::triggerEvent(Astronaut* a) const {
    std::vector<std::string> descriptions;
    for (const auto& event : activeEvents_) {
        event->execute(*a);
        descriptions.push_back(event->getDescription());
    }
    return descriptions;
}

void Module::addEvent(std::unique_ptr<Event> event) {
    activeEvents_.push_back(std::move(event));
}

size_t Module::getActiveEventCount() const {
    return activeEvents_.size();
}

void Module::resolveEvent(const int index) {
    if (index < 0 || index >= static_cast<int>(activeEvents_.size())) return;
    activeEvents_[index]->resolve();
    activeEvents_.erase(activeEvents_.begin() + index);
}

std::string Module::getActiveEventDescription(const int index) const {
    if (index < 0 || index >= static_cast<int>(activeEvents_.size())) return "";
        return activeEvents_[index]->getDescription();
}