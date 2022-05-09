#include <iostream>
#include <string>
#include "utility.h"

int main(int argc, char** argv) {

    bool isTablePrint = utilities::hasArgument(argc, argv, "-table");
    if (!isTablePrint) {
        int maxValue = utilities::getMaxArgument(argc, argv);
        std::string name = utilities::getName();
        int value = utilities::getRandomNumber(maxValue);
        unsigned int attempts = utilities::guess(value);

        utilities::saveScore(name, attempts);
    }
    utilities::printStats();
}