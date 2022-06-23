//
// Created by elmar on 07/04/2022.
//

#ifndef CPPASSIGNMENT5_LOGGER_H
#define CPPASSIGNMENT5_LOGGER_H


#include <string>
#include <ctime>
#include "../writer/FileWriter.h"

class Logger {
public:
    // gets the singleton instance of Logger
    static Logger &get();

    void log(const std::string &msg);

private:
    // logging file
    FileWriter m_out;

    // private, default constructor
    Logger();
};


#endif //CPPASSIGNMENT5_LOGGER_H
