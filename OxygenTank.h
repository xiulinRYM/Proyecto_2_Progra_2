//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_OXYGENTANK_H
#define PROYECTO_2_PROGRA_2_OXYGENTANK_H
#include "Item.h"


class OxygenTank: public Item
{
    public:
    OxygenTank():Item("Oxygen Tank"){}
    ~OxygenTank()override=default;
    void use(Astronaut& astronaut) override;

};


#endif //PROYECTO_2_PROGRA_2_OXYGENTANK_H
