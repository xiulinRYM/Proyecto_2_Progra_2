#include "../../include/events/MeteorStrike.h"

void MeteorStrike::execute(Astronaut& a) override {
    if (!isResolved) {
        Module* currentModule = a.getCurrentModule();
        if (currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 20);
        }
    }
}