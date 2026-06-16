//
// Created by xiuli on 7/6/2026.
//


#include <stdexcept>
#include "../../include/astronaut/Astronaut.h"
#include "../../include/astronaut/items/Item.h"
#include "../../include/astronaut/Inventory.h"
#include "../../include/world/Module.h"

Astronaut::Astronaut(): currentModule_(nullptr),inventory_(std::make_unique<Inventory>()), health_(100), oxygen_(100) , energy_(100)
{}

int Astronaut::getHealth() const
{
    return health_;
}

void Astronaut::setHealth(int value)
{
    if (value < 0) health_ = 0;
    else if (value > 130) health_=130;
    else health_=value;

}

int Astronaut::getOxygen() const
{
    return oxygen_;
}

void Astronaut::setOxygen(int value)
{
    if (value < 0) oxygen_ = 0;
    else if (value > 130) oxygen_ = 130;
    else oxygen_ = value;
}

int Astronaut::getEnergy() const
{
    return energy_;
}
void Astronaut::setEnergy(int value)
{
    if (value < 0) energy_ = 0;
    else if (value > 130) energy_ = 130;
    else energy_ = value;
}

void Astronaut::applyDamage(int amount)
{
    setHealth(getHealth()-amount);
}

bool Astronaut::isAlive() const
{
    return health_>0&&oxygen_>0;
}

Module* Astronaut::getCurrentModule() const
{
    return currentModule_;
}

Inventory* Astronaut::getInventory() const
{
    return inventory_.get();
}

void Astronaut::setCurrentModule(Module* module)
{
    currentModule_=module;
}

void Astronaut::move(Module* target)
{
    if (target == nullptr) {
        throw std::invalid_argument("Target module cannot be null");
    }
    if (currentModule_ != nullptr) {
        bool connected = false;
        for (Module* m : currentModule_->getConnectedModules()) {
            if (m == target) {
                connected = true;
                break;
            }
        }
        if (!connected) {
            throw std::invalid_argument("Target module is not connected to current module");
        }
    }
    setCurrentModule(target);
}

void Astronaut::takeItem(std::unique_ptr<Item> item)
{
    if (item == nullptr)
        throw std::invalid_argument("cannot take a null item");
    inventory_->addItem(std::move(item));
}

void Astronaut::useItem(int pos)
{
    if (pos < 0 || pos >= (int)inventory_->getSize()) {
        throw std::out_of_range("Invalid inventory position");
    }
    Item* item = inventory_->getItem(pos);
    if (item == nullptr) {
        throw std::runtime_error("Item is null");
    }
    item->use(*this);
    inventory_->removeItem(pos);
}

void Astronaut::applyEnergyDrain(int amount)
{
    setEnergy(getEnergy()-amount);
}

void Astronaut::applyOxygenDrain(int amount)
{
    setOxygen(getOxygen()-amount);
}



