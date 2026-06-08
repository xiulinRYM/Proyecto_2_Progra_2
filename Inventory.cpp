//
// Created by xiuli on 7/6/2026.
//

#include "Inventory.h"

void Inventory::addItem(Item* item)
{
    items_.push_back(item);
}
void Inventory::removeItem(int pos)
{
    items_.erase(items_.begin() + pos);
}
Item* Inventory::getItem(int pos)
{
    return items_[pos];
}
