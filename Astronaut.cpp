//
// Created by xiuli on 7/6/2026.
//

#include "Astronaut.h"

#include <stdexcept>

#include "Item.h"
#include "Inventory.h"

Astronaut::Astronaut(): currentModule_(nullptr),inventory_(std::make_unique<Inventory>()), health_(100), oxygen_(100) , energy_(100)
{}

int Astronaut::getHealth() const
{
    return health_;
}

void Astronaut::setHealth(int value)
{
    health_=(value < 0) ? 0 : value;
}

int Astronaut::getOxygen() const
{
    return oxygen_;
}

void Astronaut::setOxygen(int value)
{
    oxygen_=(value < 0) ? 0 : value;
}

int Astronaut::getEnergy() const
{
    return energy_;
}
void Astronaut::setEnergy(int value)
{
    energy_=(value < 0) ? 0 : value;
}

void Astronaut::applyDamage(int amount)
{
    setHealth(getHealth()-amount);
}

bool Astronaut::isAlive() const
{
    return health_>0;
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
    //  verify target is connected to currentModule_
    setCurrentModule(target);
}

void Astronaut::takeItem(Item* item)
{
    if (item == nullptr)
    {
        throw std::invalid_argument("cannot take a null item");
    }
inventory_->addItem(item);
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



