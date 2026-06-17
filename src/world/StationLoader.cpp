#include <iostream>
#include <fstream>
#include <sstream>

#include "world/StationLoader.h"
#include "world/Module.h"
#include "astronaut/items/Item.h"
#include "astronaut/items/ItemFactory.h"

void StationLoader::loadModulesData(const std::string& filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    int moduleCount = 0;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, moduleName;

        getline(s, type, ';');
        getline(s, moduleName, ';' );
        if (!moduleName.empty() && moduleName.back() == '\r')
            moduleName.pop_back();

        if (type == "MODULE") {
            station.addModule(std::make_unique<Module>(moduleName));
            moduleCount++;
        }
    }
    std::cout << "Loaded modules: " << moduleCount << std::endl;
}

void StationLoader::loadConnectionsData(const std::string& filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    int connectionCount = 0;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, module1, module2;

        getline(s, type, ';');
        getline(s, module1, ';' );
        getline(s, module2, ';' );
        if (!module1.empty() && module1.back() == '\r') {
            module1.pop_back();
        }
        if (!module2.empty() && module2.back() == '\r') {
            module2.pop_back();
        }

        if (type == "CONNECTION") {
            Module* m1 = station.getModule(module1);
            connectionCount++;
            if (Module* m2 = station.getModule(module2); m1 != nullptr && m2 != nullptr) {
                m1->addConnection(m2);
                m2->addConnection(m1);
            }
        }
    }
    std::cout << "Loaded connections: " << connectionCount<< std::endl;
}

void StationLoader::loadItemsData(const std::string& filename, SpaceStation &station) {
    std::ifstream file_(filename);
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;
    int itemCount = 0;
    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, moduleName, item_;

        getline(s, type, ';');
        getline(s, moduleName, ';');
        getline(s, item_, ';');

        if (!moduleName.empty() && moduleName.back() == '\r') {
            moduleName.pop_back();
        }
        if (!item_.empty() && item_.back() == '\r') {
            item_.pop_back();
        }

        if (type == "ITEM") {
            try{
            std::unique_ptr<Item> item = ItemFactory::create(item_);
            itemCount++;
            if (Module* m = station.getModule(moduleName); m != nullptr) {
                m->addItem(std::move(item));
            } else {
                std::cerr << "Module not found for item: " << moduleName << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error creating item '" << item_ << "': " << e.what() << std::endl;
        }
        }
    }
    std::cout << "Loaded items: " << itemCount << std::endl << std::endl;
}



std::string StationLoader::loadStartData(const std::string &filename) {
    std::ifstream file_(filename);
    std::string line;
    if (!file_.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    while (std::getline(file_, line)) {
        std::stringstream s(line);
        std::string type, startModule;

        getline(s, type, ';');
        getline(s, startModule, ';');

        if (!startModule.empty() && startModule.back() == '\r') {
            startModule.pop_back();
        }

        if (type == "START") {
            return startModule;
        }
    }
    return "";
}

void StationLoader::load(const std::string &filename, SpaceStation &station) {
    loadModulesData(filename, station);
    loadConnectionsData(filename, station);
    loadItemsData(filename, station);
}
