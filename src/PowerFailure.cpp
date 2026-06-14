#include "PowerFailure.h"

void PowerFailure::execute(Astronaut& a) {
    if (!isResolved) {
        a.setEnergy(a.getEnergy() - 20);
    }
}