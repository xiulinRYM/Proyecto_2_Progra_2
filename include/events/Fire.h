#ifndef FIRE_H
#define FIRE_H

#include "Event.h"
class Astronaut;
class Module;

class Fire : public Event {
public:
    Fire() : Event("Incendio en el modulo.") {}

    void execute(Astronaut& a) override;
};

#endif