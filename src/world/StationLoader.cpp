#include <iostream>
#include <fstream>
#include <sstream>

#include "world/StationLoader.h"
#include "world/Module.h"
#include "astronaut/items/Item.h"

void StationLoader::loadModulesData(std::string filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, moduleName;

        getline(s, type, ';');
        getline(s, moduleName, ';' );

        if (type == "MODULE") {
            auto* m = new Module(moduleName);
            station.addModule(m);
        }
    }
}

void StationLoader::loadConnectionsData(std::string filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, module1, module2;

        getline(s, type, ';');
        getline(s, module1, ';' );
        getline(s, module2, ';' );

        if (type == "CONNECTION") {
            Module* m1 = station.getModule(module1);
            if (Module* m2 = station.getModule(module2); m1 != nullptr && m2 != nullptr) {
                m1->addConnection(m2);
                m2->addConnection(m1);
            }
        }
    }
}

void StationLoader::loadItemsData(std::string filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, moduleName, item_;

        getline(s, type, ';');
        getline(s, moduleName, ';');
        getline(s, item_, ';');

        if (type == "ITEM") {
            std::unique_ptr<Item> item = ItemFactory::createItem(item_);
            if (item != nullptr) {
                if (Module* m = station.getModule(moduleName); m != nullptr) {
                    m->addItem(std::move(item));
                }
            }
        }
    }
}

std::string StationLoader::loadStartData(const std::string &filename) {
    std::ifstream file_(filename);
    std::string line;

    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, startModule;
        getline(s, type, ';');
        getline(s, startModule, ';');

        if (type == "START") {
            return startModule;
        }
    }
    return "";
}

void StationLoader::load(std::string filename, SpaceStation &station) {
    loadModulesData(filename, station);
    loadConnectionsData(filename, station);
    loadItemsData(filename, station);
}
