//
// Created by xiuli on 7/6/2026.
//
#include "../../include/astronaut/items/Item.h"
#include "../../include/astronaut/Inventory.h"
#include <stdexcept>

void Inventory::addItem(std::unique_ptr<Item> item)
{
    items_.push_back(std::move(item));
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
    return items_[pos].get();
}

int Inventory::getSize() const
{
    return static_cast<int>(items_.size());
}

std::vector<std::string> Inventory::getItemNames() const {
    std::vector<std::string> names;
    for (const auto& item : items_) {
        names.push_back(item->getName());
    }
    return names;
}
