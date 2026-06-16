#include "../../include/events/OxygenLeak.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"
void OxygenLeak::execute(Astronaut& a)  {
    if (!isResolved) {
        a.setOxygen(a.getOxygen() - 15);

        if (Module* currentModule = a.getCurrentModule(); currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 5);
        }
    }
}