//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ENERGYCELL_H
#define PROYECTO_2_PROGRA_2_ENERGYCELL_H
#include "../../Item.h"


class EnergyCell:public Item
{
    public:
    EnergyCell():Item("Energy Cell"){}
    ~EnergyCell() override = default;
    void use(Astronaut& astronaut) override;

};


#endif //PROYECTO_2_PROGRA_2_ENERGYCELL_H
