#ifndef PROYECTO_2_PROGRA_2_STATIONLOADER_H
#define PROYECTO_2_PROGRA_2_STATIONLOADER_H

#include "world/SpaceStation.h"
#include <string>

class StationLoader {
    static void loadModulesData(const std::string& filename, SpaceStation& station);
    static void loadConnectionsData(const std::string& filename, SpaceStation& station);
    static void loadEventsData(const std::string& filename, SpaceStation& station);
    static void loadItemsData(const std::string& filename, SpaceStation& station);
public:
    StationLoader() = default;

    static void load(const std::string &filename, SpaceStation& station);
    static std::string loadStartData(const std::string &filename);
};

#endif //PROYECTO_2_PROGRA_2_STATIONLOADER_H