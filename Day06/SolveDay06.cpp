#include <vector>
#include <string>
#include <iostream>
#include "SolveDay06.h"
#include "UtilFunctions.h"

#define PREFIX_LENGTH 11

void SolveDay06::solve(std::vector<std::string> input) {
    std::vector<int> times = UtilFunctions::splitToInt(input[0].substr(PREFIX_LENGTH, input[0].length() - PREFIX_LENGTH), " ");
    std::vector<int> distances = UtilFunctions::splitToInt(input[1].substr(PREFIX_LENGTH, input[1].length() - PREFIX_LENGTH), " ");
    long long total = 1;
    for (int i = 0; i < times.size(); i++) {
        int time = times[i];
        int distance = distances[i];
        int localTotal = 0;
        for (int c = 0; c < time; c++)
            if ((time - c) * c > distance)
                localTotal++;
        total *= localTotal;
    }
    std::cout << total << std::endl;
}
