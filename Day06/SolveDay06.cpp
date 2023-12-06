#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "SolveDay06.h"
#include "UtilFunctions.h"

#define PREFIX_LENGTH 11

void SolveDay06::solve(std::vector<std::string> input) {
    unsigned long long timee = std::stoll(UtilFunctions::split(std::regex_replace(input[0], std::regex("\\s"), ""), ":")[1]);
    unsigned long long distancee = std::stoll(UtilFunctions::split(std::regex_replace(input[1], std::regex("\\s"), ""), ":")[1]);
    unsigned long long total = 0;
    for (long long c = 0; c < timee; c++)
        if ((timee - c) * c > distancee)
            total++;
    std::cout << total << std::endl;
}
