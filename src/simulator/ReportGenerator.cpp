//
// Created by danie on 11/6/2026.
//

#include "../../ReportGenerator.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

ReportGenerator::ReportGenerator(const std::string& fileName) {
    reportFileName = fileName;
    missionResult = "UNKNOWN";
    finalOxygen = 0;
    finalEnergy = 0;
    finalHealth = 0;
    finalModules = 0;
}

void ReportGenerator::setMissionResult(const std::string& result) {
    missionResult = result;
}

void ReportGenerator::setFinalStats(int oxygen, int energy, int health, int modules) {
    finalOxygen = oxygen;
    finalEnergy = energy;
    finalHealth = health;
    finalModules = modules;
}

std::string ReportGenerator::buildReport() const {
    std::string report = "";
    report += "=======================================\n";
    report += "        FINAL MISSION REPORT          \n";
    report += "=======================================\n";
    report += "Result         : " + missionResult + "\n";
    report += "Final Health   : " + std::to_string(finalHealth) + "\n";
    report += "Final Oxygen   : " + std::to_string(finalOxygen) + "\n";
    report += "Final Energy   : " + std::to_string(finalEnergy) + "\n";
    report += "Modules visited: " + std::to_string(finalModules) + "\n";
    report += "Events occurred: " + std::to_string(savedLog.size()) + "\n";
    return report;
}

void ReportGenerator::generate(const Logger& logger) {
    savedLog = logger.getLog();
    std::cout << buildReport();
}

void ReportGenerator::saveToFile() const {
    std::ofstream file(reportFileName);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open report file");
        return;
    }

    file << buildReport();
    file << "--- EVENT SUMMARY ---" << std::endl;

    for (const std::string& entry : savedLog) {
        file << entry << "\n";
    }

    file.close();
    std::cout << "Report saved to: " << reportFileName << std::endl;
}

