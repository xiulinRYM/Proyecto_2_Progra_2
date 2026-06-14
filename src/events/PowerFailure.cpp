#include "../../include/events/PowerFailure.h"

void PowerFailure::execute(Astronaut& a) override {
    if (!isResolved) {
        a.setEnergy(a.getEnergy() - 20);
    }
}