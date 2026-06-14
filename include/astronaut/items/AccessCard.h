//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ACCESSCARD_H
#define PROYECTO_2_PROGRA_2_ACCESSCARD_H
#include "../../Item.h"


class AccessCard:public Item
{
    public:
    AccessCard():Item("Access Card"){}
    void use(Astronaut& astronaut) override;
    ~AccessCard()override=default;
};


#endif //PROYECTO_2_PROGRA_2_ACCESSCARD_H
