//
// Created by xiuli on 7/6/2026.
//

#include "RepairKit.h"

#include <stdexcept>

#include "Astronaut.h"

void RepairKit::use(Astronaut& astronaut)
{
    int newValue = astronaut.getHealth() + 20;
    if (newValue > 130) {
        throw std::overflow_error("Health already at maximum capacity");
    }
    astronaut.setHealth(newValue);
}
