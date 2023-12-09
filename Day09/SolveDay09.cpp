#include <vector>
#include <string>
#include <iostream>
#include "SolveDay09.h"
#include <numeric>
#include "UtilFunctions.h"


void SolveDay09::solve(std::vector<std::string> input) {
    long long total = 0;
    for (const auto &line: input) {
        std::vector<std::vector<long long>> numbers;
        numbers.push_back(UtilFunctions::splitToLongLong(line, " "));
        long long localTotal = 0;
        for (int i = 0; i < numbers.size(); i++) {
            int allZero = 1;
            numbers.emplace_back();
            for (int j = 1; j < numbers[i].size(); j++) {
                long long numToAdd = -numbers[i][j - 1] + numbers[i][j];
                numbers[i + 1].push_back(numToAdd);
                if(numToAdd != 0)
                    allZero = 0;
            }
            localTotal+=numbers[i][numbers[i].size()-1];
            if(allZero){
                break;
            }
        }
        total+=localTotal;
    }
    std::cout << total << std::endl;
}
