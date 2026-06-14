#include "OxygenLeak.h"

void OxygenLeak::execute(Astronaut& a) {
    if (!isResolved) {
        a.setOxygen(a.getOxygen() - 15);
    }
}