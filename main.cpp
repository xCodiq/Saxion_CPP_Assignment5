/**
 * Name : Elmar Blume
 * Student Number: 516099
 */

#include "logger/Logger.h"

int main() {
    auto &logger = Logger::get();

    logger.log("Welcome to the start of this message!");
    logger.log("You just logged your second line, good job ;d");
}
