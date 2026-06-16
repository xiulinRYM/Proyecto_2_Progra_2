#ifndef FIRE_H
#define FIRE_H

#include "Event.h"
class Astronaut;
class Module;

class Fire : public Event {
public:
    Fire() : Event("Fire detected in the module") {}

    void execute(Astronaut& a) override;
};

#endif