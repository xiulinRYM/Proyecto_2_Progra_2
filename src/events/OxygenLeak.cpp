#include "../../include/events/OxygenLeak.h"

void OxygenLeak::execute(Astronaut& a) override {
    if (!isResolved) {
        a.setOxygen(a.getOxygen() - 15);
    }
}