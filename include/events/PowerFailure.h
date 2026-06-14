#ifndef POWERFAILURE_H
#define POWERFAILURE_H

#include "Event.h"
class Astronaut;
class Module;

class PowerFailure : public Event {
public:
    PowerFailure() : Event("Fallo critico de energia.") {}

    void execute(Astronaut& a) override;
};

#endif