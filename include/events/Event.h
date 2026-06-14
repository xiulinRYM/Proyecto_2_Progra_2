#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Astronaut.h"

class Event {
protected:
    std::string description;
    bool isResolved;

public:
    Event(std::string desc) : description(desc), isResolved(false) {}

    virtual ~Event() = default;

    virtual void execute(Astronaut& a) = 0;

    std::string getDescription() { return description; }
    void resolve() { isResolved = true; }
};

#endif