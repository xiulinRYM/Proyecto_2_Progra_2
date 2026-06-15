#pragma once
#include "../events/Event.h"
#include "../../include/astronaut/items/Item.h"
#include <vector>
#include <string>

class Module {
    std::string name_;
    int integrity_;
    std::vector<Module*> connectedModules_;
    std::vector<Item*> items_;
    std::vector<Event*> activeEvents_;

public:
    explicit Module(std::string name);
    void addItem(Item* item);
    void addConnection(Module* module);
    void triggerEvent(Astronaut* a) const;
    [[nodiscard]] int getIntegrity() const;
    void setIntegrity(int integrity);
    std::string getName();
    std::vector<Item*> getItems();
    std::vector<Module*> getConnectedModules();
    [[nodiscard]] bool isDestroyed() const;
    void removeItem(Item* item);
};