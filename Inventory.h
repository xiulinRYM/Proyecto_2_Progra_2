//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_INVENTORY_H
#define PROYECTO_2_PROGRA_2_INVENTORY_H
#include <vector>
class Item;


class Inventory
{
    public:
    Inventory()= default;
    void addItem(Item* item);
    [[nodiscard]]Item* getItem(int pos) const;
    void removeItem(int pos);
    [[nodiscard]]int getSize() const;

    private:
    std::vector<Item* > items_;
};


#endif //PROYECTO_2_PROGRA_2_INVENTORY_H
