//
// Created by xiuli on 15/6/2026.
//
#include "astronaut/items/ItemFactory.h"

#include <functional>
#include <map>

#include "astronaut/items/EnergyCell.h"
#include "astronaut/items/OxygenTank.h"
#include "astronaut/items/RepairKit.h"
#include "astronaut/items/RepairTool.h"

std::unique_ptr<Item> ItemFactory::create(const std::string& type)
{
   static const std::map<std::string, std::function<std::unique_ptr<Item>()>> creators ={
      {"EnergyCell", [](){return std::make_unique<EnergyCell>();}},
      {"OxygenTank", [](){return std::make_unique<OxygenTank>();}},
      {"RepairKit", [](){return std::make_unique<RepairKit>();}},
      {"RepairTool",[](){return std::make_unique<RepairTool>();}},
   };

   auto it=creators.find(type);
   if(it==creators.end())
      throw std::invalid_argument("Unknown item type" + type);
   return it->second();
}
