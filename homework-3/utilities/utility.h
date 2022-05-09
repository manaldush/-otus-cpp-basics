#pragma once

#include <string>
namespace utilities {

    std::string getName();

    int getRandomNumber(int maxValue);

    unsigned int guess(int value);

    void saveScore(std::string name, unsigned int attempts);

    void printStats();

    char* getArgument(int argc, char** argv, char* argName);

    int getMaxArgument(int argc, char** argv);

    bool hasArgument(int argc, char** argv, char* argName);
}