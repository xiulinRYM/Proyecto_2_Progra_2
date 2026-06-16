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
    std::vector<std::unique_ptr<Event>> activeEvents_;

public:
    explicit Module(std::string name);
    ~Module() = default;
    void addItem(std::unique_ptr<Item> item);
    void addConnection(Module* module);
    void triggerEvent(Astronaut* a);
    [[nodiscard]] int getIntegrity() const;
    void setIntegrity(int integrity);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] std::vector<Item*> getItems() const;
    [[nodiscard]] std::vector<Module*> getConnectedModules() const;
    [[nodiscard]] bool isDestroyed() const;
    std::unique_ptr<Item> extractItem(const Item* item);
    void addEvent(std::unique_ptr<Event> event);
};