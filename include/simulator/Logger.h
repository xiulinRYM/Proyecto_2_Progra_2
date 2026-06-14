//
// Created by danie on 11/6/2026.
//

#ifndef PROYECTO_2_PROGRA_2_LOGGER_H
#define PROYECTO_2_PROGRA_2_LOGGER_H
#include <string>
#include <vector>

class Logger {
    public:
    Logger( const std::string& filename = "report.txt" );
    void writeEntry(const std::string& entry);
    void exportToFile() const;
    const std::vector<std::string>& getLog() const;
    void writeHeader();
private:
    std::vector<std::string> eventLog;
    std::string logFileName;
};


#endif //PROYECTO_2_PROGRA_2_LOGGER_H