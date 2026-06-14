#include "../../include/events/MeteorStrike.h"
#include "../../include/astronaut/Astronaut.h"
#include "../../include/world/Module.h"

void MeteorStrike::execute(Astronaut& a)  {
    if (!isResolved) {
        Module* currentModule = a.getCurrentModule();
        if (currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 20);
        }
    }
}