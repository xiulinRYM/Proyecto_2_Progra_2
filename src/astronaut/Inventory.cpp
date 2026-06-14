//
// Created by xiuli on 7/6/2026.
//

#include "../../include/astronaut/Inventory.h"
#include <stdexcept>

void Inventory::addItem(Item* item)
{
    items_.push_back(item);
}
void Inventory::removeItem(int pos)
{
    if (pos < 0 || pos >= static_cast<int>(items_.size())) {
        throw std::out_of_range("Invalid inventory position");
    }
    items_.erase(items_.begin() + pos);
}
Item* Inventory::getItem(int pos) const
{
    if (pos < 0 || pos >= static_cast<int>(items_.size())) {
        throw std::out_of_range("Invalid inventory position");
    }
    return items_[pos];
}

int Inventory::getSize() const
{
    return static_cast<int>(items_.size());
}
