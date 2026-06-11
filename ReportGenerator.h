//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_REPORTGNERATOR_H
#define PROYECTO_2_PROGRA_2_REPORTGNERATOR_H

#include <string>
#include <vector>
#include "Logger.h"

class ReportGenerator {
public:
    ReportGenerator(const std::string& fileName = "final_report.txt");
    void setMissionResult(const std::string& result);
    void setFinalStats(int oxygen, int energy, int health, int modules);
    void generate(const Logger& logger);
    void saveToFile() const;

private:
    std::string reportFileName;
    std::string missionResult;
    int finalOxygen;
    int finalEnergy;
    int finalHealth;
    int finalModules;
    std::vector<std::string> savedLog;

    std::string buildReport() const;
};

#endif //PROYECTO_2_PROGRA_2_REPORTGNERATOR_H