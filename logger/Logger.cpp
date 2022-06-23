//
// Created by elmar on 07/04/2022.
//

#include <sstream>
#include "Logger.h"

Logger &Logger::get() {
    static Logger instance{};
    return instance;
}

void Logger::log(const std::string &msg) {
    if (!this->m_out.is_open()) return;

    auto time = std::time(nullptr);
    char time_formatted[100];

    if (std::strftime(time_formatted, sizeof(time_formatted), "%c", std::localtime(&time))) {
        std::stringstream stream{};
        stream << "[" << time_formatted << "]: " << msg << "\n";

        this->m_out.write(stream.str());
        std::cout << stream.str();
    }
}

Logger::Logger() : m_out("ass5.txt") {

}
