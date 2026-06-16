//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ACCESSCARD_H
#define PROYECTO_2_PROGRA_2_ACCESSCARD_H
#include "Item.h"


class RepairTool:public Item
{
    public:
    RepairTool():Item("Access Card"){}
    void use(Astronaut& astronaut) override;
    ~RepairTool()override=default;
};


#endif //PROYECTO_2_PROGRA_2_ACCESSCARD_H
