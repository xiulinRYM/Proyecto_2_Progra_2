//
// Created by xiuli on 7/6/2026.
//

#include "../../EnergyCell.h"

#include <stdexcept>

#include "Astronaut.h"

void EnergyCell::use(Astronaut& astronaut)
{
    int newValue = astronaut.getEnergy() + 25;
    if (newValue > 130) {
        throw std::overflow_error("Energy already at maximum capacity");
    }
    astronaut.setEnergy(newValue);
}
