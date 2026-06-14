#include "../../include/events/PowerFailure.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"
void PowerFailure::execute(Astronaut& a)  {
    if (!isResolved) {
        a.setEnergy(a.getEnergy() - 20);
    }
}