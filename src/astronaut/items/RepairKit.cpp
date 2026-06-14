//
// Created by xiuli on 7/6/2026.
//

#include "../../../include/astronaut/items/RepairKit.h"
#include "../../../include/astronaut/Astronaut.h"

void RepairKit::use(Astronaut& astronaut)
{
    int newValue = astronaut.getHealth() + 20;
    astronaut.setHealth(newValue);
}
