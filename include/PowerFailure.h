#ifndef POWERFAILURE_H
#define POWERFAILURE_H

#include "Event.h"
#include "Astronaut.h"

class PowerFailure : public Event {
public:
    PowerFailure() : Event("Fallo critico de energia.") {}

    void execute(Astronaut& a) override;
};

#endif