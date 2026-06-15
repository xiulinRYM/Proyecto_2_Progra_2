//
// Created by xiuli on 7/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_INVENTORY_H
#define PROYECTO_2_PROGRA_2_INVENTORY_H
#include <memory>
#include <vector>
class Item;


class Inventory
{
    public:
    Inventory()= default;
    void addItem(std::unique_ptr<Item> item);
    [[nodiscard]]Item* getItem(int pos) const;
    void removeItem(int pos);
    [[nodiscard]]int getSize() const;
    [[nodiscard]] std::vector<std::string> getItemNames() const;

    private:
    std::vector<std::unique_ptr<Item> > items_;
};


#endif //PROYECTO_2_PROGRA_2_INVENTORY_H
