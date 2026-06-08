//
// Created by xiuli on 7/6/2026.
//

#include "Inventory.h"

#include <stdexcept>

void Inventory::addItem(Item* item)
{
    items_.push_back(item);
}
void Inventory::removeItem(int pos)
{
    if (pos < 0 || pos >= (int)items_.size()) {
        throw std::out_of_range("Invalid inventory position");
    }
    items_.erase(items_.begin() + pos);
}
Item* Inventory::getItem(int pos)
{
    if (pos < 0 || pos >= (int)items_.size()) {
        throw std::out_of_range("Invalid inventory position");
    }
    return items_[pos];
}

int Inventory::getSize()
{
    return items_.size();
}
