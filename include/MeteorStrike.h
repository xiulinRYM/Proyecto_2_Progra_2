// MeteorStrike.h
#ifndef METEORSTRIKE_H
#define METEORSTRIKE_H

#include "Event.h"
#include "Astronaut.h"
#include "Module.h"

class MeteorStrike : public Event {
public:
    MeteorStrike() : Event("Impacto de meteorito detectado.") {}

    void execute(Astronaut& a) override;
};

#endif