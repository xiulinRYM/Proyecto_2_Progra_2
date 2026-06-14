#include "Fire.h"

void Fire::execute(Astronaut& a) override {
    if (!isResolved) {
        a.setHealth(a.getHealth() - 5);
        a.setOxygen(a.getOxygen() - 10);

        Module* currentModule = a.getCurrentModule();
        if (currentModule != nullptr) {
            currentModule->setIntegrity(currentModule->getIntegrity() - 10);
        }
    }
}