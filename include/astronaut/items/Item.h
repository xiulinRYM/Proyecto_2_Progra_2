//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ITEM_H
#define PROYECTO_2_PROGRA_2_ITEM_H
#include <string>
class Astronaut;
class Item
{
    public:
    Item(std::string name):name_(std::move(name)){}
    [[nodiscard]] std::string getName() const{return name_;};
    virtual void use(Astronaut&)=0;
    virtual ~Item()=default;
    protected:
    std::string name_;
};
#endif //PROYECTO_2_PROGRA_2_ITEM_H
