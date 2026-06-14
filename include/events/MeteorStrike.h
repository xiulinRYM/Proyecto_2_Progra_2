#ifndef METEORSTRIKE_H
#define METEORSTRIKE_H

#include "Event.h"
class Astronaut;
class Module;

class MeteorStrike : public Event {
public:
    MeteorStrike() : Event("Impacto de meteorito detectado.") {}

    void execute(Astronaut& a) override;
};

#endif