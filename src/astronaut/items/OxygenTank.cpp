//
// Created by xiuli on 7/6/2026.
//

#include "../../../include/astronaut/items/OxygenTank.h"
#include "../../../include/astronaut/Astronaut.h"

void OxygenTank::use(Astronaut& astronaut)
{
    int newValue = astronaut.getOxygen() + 30;
    astronaut.setOxygen(newValue);
}
