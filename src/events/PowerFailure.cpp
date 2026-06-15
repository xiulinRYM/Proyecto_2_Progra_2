#include "../../include/events/PowerFailure.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"
void PowerFailure::execute(Astronaut& a)  {
    if (!isResolved) {
        a.setEnergy(a.getEnergy() - 20);

        Module* currentModule = a.getCurrentModule();
        if (currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 5);
        }
    }
}