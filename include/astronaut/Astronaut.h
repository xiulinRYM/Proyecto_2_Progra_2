//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ASTRONAUT_H
#define PROYECTO_2_PROGRA_2_ASTRONAUT_H
#include <memory>
#include <vector>
#include <string>
class Module;
class Item;
class Inventory;

class Astronaut
{
    public:
    Astronaut();
    void useItem(int pos);
    void takeItem(Item* item);
    void move(Module* target);
    [[nodiscard]] int getHealth()const;
    [[nodiscard]] int getOxygen()const;
    [[nodiscard]] int getEnergy()const;
    [[nodiscard]] Module* getCurrentModule() const;
    [[nodiscard]] Inventory* getInventory() const;
    [[nodiscard]] bool isAlive() const;
    void setCurrentModule(Module* module);
    void setHealth(int value);
    void setOxygen(int value);
    void setEnergy(int value);
    void applyDamage(int amount);
    ~Astronaut()=default;

    private:

    Module* currentModule_;
    std::unique_ptr<Inventory> inventory_;
    int health_;
    int oxygen_;
    int energy_;

};


#endif //PROYECTO_2_PROGRA_2_ASTRONAUT_H
