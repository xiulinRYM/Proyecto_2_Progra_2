//
// Created by xiuli on 7/6/2026.
//

#include "OxygenTank.h"

#include "Astronaut.h"

void OxygenTank::use(Astronaut& astronaut)
{
    astronaut.setOxygen(astronaut.getOxygen()+30);
}
