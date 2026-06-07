//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ASTRONAUT_H
#define PROYECTO_2_PROGRA_2_ASTRONAUT_H
#include <vector>
#include <string>
class Item;
class Astronaut
{
    public:
    Astronaut();
    void useItem(Item& item);
    void pickItem(Item& item);
    void move(std::string destination);
    [[nodiscard]] int getHealth()const;
    [[nodiscard]] int getOxygen()const;
    [[nodiscard]] int getStamina()const;
    void setHealth(int value);
    void setOxygen(int value);
    void setStamina(int value);
    ~Astronaut()=default;
    private:
    int health_;
    int oxygen_;
    int stamina_;

};


#endif //PROYECTO_2_PROGRA_2_ASTRONAUT_H
