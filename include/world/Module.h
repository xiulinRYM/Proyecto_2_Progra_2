#pragma once
#include "../events/Event.h"
#include "../../include/astronaut/items/Item.h"
#include <vector>
#include <string>
#include <algorithm>

class Module {

public:
    Module(std::string name);
    void addItem(Item* item);
    void addConnection(Module* module);
    void triggerEvent(Event* event);
    int getIntegrity();
    void setIntegrity(int integrity);
    std::string getName();
    std::vector<Item*> getItems();
    std::vector<Module*> getConnectedModules();
    bool isDestroyed();
    void removeItem(Item* item);

private:
    std::string name_;
    int integrity_;
    std::vector<Module*> connectedModules_;
    std::vector<Item*> items_;
    std::vector<Event*> activeEvents_;
};