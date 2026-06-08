//
// Created by xiuli on 7/6/2026.
//

#include "EnergyCell.h"

#include "Astronaut.h"

void EnergyCell::use(Astronaut& astronaut)
{
    astronaut.setEnergy(astronaut.getEnergy()+25);
}
