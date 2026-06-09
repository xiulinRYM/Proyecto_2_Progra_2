#pragma once
#include "Event.h"
#include "Item.h"
#include <vector>

class Module {
    std::string name_;
    int integrity_;
    std::vector<Module*> connectedModules_;
    std::vector<Item*> items_;
    std::vector<Event*> activeEvents_;
public:
    void addConnection(Module* module);
    void triggerEvent(Event* event);
    int getIntegrity();
    void setIntegrity(int integrity);
    std::string getName();
    std::vector<Item*> getItems();
    std::vector<Module*> getConnectedModules();
    bool isDestroyed();
    void removeItem(Item* item);
};