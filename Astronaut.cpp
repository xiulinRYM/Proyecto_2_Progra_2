//
// Created by xiuli on 7/6/2026.
//

#include "Astronaut.h"
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

