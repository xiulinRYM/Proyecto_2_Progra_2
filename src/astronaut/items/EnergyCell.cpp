//
// Created by xiuli on 7/6/2026.
//

#include "../../../include/astronaut/items/EnergyCell.h"
#include "../../../include/astronaut/Astronaut.h"


void EnergyCell::use(Astronaut& astronaut)
{
    int newValue = astronaut.getEnergy() + 25;
    astronaut.setEnergy(newValue);
}
