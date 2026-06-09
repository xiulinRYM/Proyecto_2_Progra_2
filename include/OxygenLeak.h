#ifndef OXYGENLEAK_H
#define OXYGENLEAK_H

#include "Event.h"
#include "Astronaut.h"

class OxygenLeak : public Event {
public:
    OxygenLeak() : Event("Fuga de oxigeno detectada.") {}

    void execute(Astronaut& a) override;
};

#endif