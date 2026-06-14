#include "MeteorStrike.h"

void MeteorStrike::execute(Astronaut& a) {
    if (!isResolved) {
        Module* currentModule = a.getCurrentModule();
        if (currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 20);
        }
    }
}