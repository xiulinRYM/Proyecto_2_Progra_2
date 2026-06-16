//
// Created by xiuli on 15/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_ITEMFACTORY_H
#define PROYECTO_2_PROGRA_2_ITEMFACTORY_H
#include <memory>
#include <string>
#include "Item.h"

class ItemFactory
{
public:
static std::unique_ptr<Item> create(const std::string& type);
};
#endif //PROYECTO_2_PROGRA_2_ITEMFACTORY_H
