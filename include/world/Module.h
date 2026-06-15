#pragma once
#include "../events/Event.h"
#include "../../include/astronaut/items/Item.h"
#include <vector>
#include <string>
#include <memory>

class Module {
    std::string name_;
    int integrity_;
    std::vector<Module*> connectedModules_;
    std::vector<std::unique_ptr<Item>> items_;
    std::vector<Event*> activeEvents_;

public:
    explicit Module(std::string name);
    void addItem(std::unique_ptr<Item> item);
    void addConnection(Module* module);
    void triggerEvent(Astronaut* a) const;
    [[nodiscard]] int getIntegrity() const;
    void setIntegrity(int integrity);
    std::string getName();
    std::vector<Item*> getItems() const;
    std::vector<Module*> getConnectedModules();
    [[nodiscard]] bool isDestroyed() const;
    void removeItem(Item* item);
    std::unique_ptr<Item> extractItem(const Item* item);
};