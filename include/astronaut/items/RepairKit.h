//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_REPAIRKIT_H
#define PROYECTO_2_PROGRA_2_REPAIRKIT_H
#include "Item.h"


class RepairKit: public Item
{
    public:
    RepairKit():Item("Repair Kit"){}
    ~RepairKit() override=default;
    void use(Astronaut& astronaut) override;
};


#endif //PROYECTO_2_PROGRA_2_REPAIRKIT_H
