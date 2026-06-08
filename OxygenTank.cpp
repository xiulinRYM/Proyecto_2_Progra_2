//
// Created by xiuli on 7/6/2026.
//

#include "OxygenTank.h"
#include <stdexcept>
#include "Astronaut.h"

void OxygenTank::use(Astronaut& astronaut)
{
    int newValue = astronaut.getOxygen() + 30;
    if (newValue > 130) {
        throw std::overflow_error("Oxygen already at maximum capacity");
    }
    astronaut.setOxygen(newValue);
}
