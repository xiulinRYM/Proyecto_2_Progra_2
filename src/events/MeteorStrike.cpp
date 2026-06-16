#include "../../include/events/MeteorStrike.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"

void MeteorStrike::execute(Astronaut& a)  {
    if (!isResolved) {
        if (Module* currentModule = a.getCurrentModule(); currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 20);
        }
    }
}