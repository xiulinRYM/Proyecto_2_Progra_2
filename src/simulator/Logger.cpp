//
// Created by danie on 11/6/2026.
//

#include "../../Logger.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
Logger::Logger(const std::string& fileName) {
    logFileName = fileName;
}
void Logger::writeEntry(const std::string& entry) {
    eventLog.push_back(entry);
    std::cout << entry<<std::endl;
}

void Logger::writeHeader() {
    writeEntry("=== SIMULATION STARTED ===");
}

void Logger::exportToFile() const {
    std::ofstream file(logFileName);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening log file");
    }
    file<<"==================="<<std::endl;
    file << " Adventure Report " << std::endl;
    file<<"==================="<<std::endl;

    for (int i = 0; i < eventLog.size(); i++) {
        file << eventLog[i] << std::endl;
    }
    file<<"==================="<<std::endl;
    file<<" Total events: "<<eventLog.size()<<std::endl;
    file.close();
    std::cout << " Report generated successfully!" << std::endl;
}
const std::vector<std::string>& Logger::getLog() const {
    return eventLog;
}
