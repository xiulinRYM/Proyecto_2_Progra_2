//
// Created by xiuli on 7/6/2026.
//

#include "../../../include/astronaut/items/RepairTool.h"
#include "../../../include/astronaut/Astronaut.h"
#include "world/Module.h"

void RepairTool::use(Astronaut& astronaut)
{
    Module* module = astronaut.getCurrentModule();
    if (module == nullptr) return;
    module->setIntegrity(module->getIntegrity() + 15);
}
