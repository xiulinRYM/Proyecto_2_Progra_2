//
// Created by xiuli on 7/6/2026.
//

#include "RepairKit.h"

#include "Astronaut.h"

void RepairKit::use(Astronaut& astronaut)
{
    astronaut.setHealth(astronaut.getHealth()+20);
}
