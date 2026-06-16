#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <utility>
class Astronaut;

class Event {
protected:
    std::string description;
    bool isResolved;

public:
    explicit Event(std::string desc) : description(std::move(desc)), isResolved(false) {}

    virtual ~Event() = default;

    virtual void execute(Astronaut& a) = 0;

    [[nodiscard]] std::string getDescription() const { return description; }
    void resolve() { isResolved = true; }
};

#endif