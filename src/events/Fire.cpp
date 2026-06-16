#include "../../include/events/Fire.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"

void Fire::execute(Astronaut& a)  {
    if (!isResolved) {
        a.setHealth(a.getHealth() - 5);
        a.setOxygen(a.getOxygen() - 10);

        if (Module* currentModule = a.getCurrentModule(); currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 10);
        }
    }
}