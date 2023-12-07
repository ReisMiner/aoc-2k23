#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "SolveDay07.h"
#include "UtilFunctions.h"

#define AMOUNT_OF_TYPES 7
//A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2
//E, D, C, B, A, 9, 8, 7, 6, 5, 4, 3, 2

std::vector<std::string> flatten(std::vector<std::vector<std::string>> &v) {
    std::vector<std::string> result;
    for (auto &sub_vector: v) {
        result.insert(result.end(), sub_vector.begin(), sub_vector.end());
    }
    return result;
}

void SolveDay07::solve(std::vector<std::string> input) {
    std::vector<std::vector<std::string>> sorted(AMOUNT_OF_TYPES);
    for (auto &item: input) {
        std::replace(item.begin(), item.end(), 'A', 'E');
        std::replace(item.begin(), item.end(), 'K', 'D');
        std::replace(item.begin(), item.end(), 'Q', 'C');
        std::replace(item.begin(), item.end(), 'J', 'B');
        std::replace(item.begin(), item.end(), 'T', 'A');
    }
    std::sort(input.begin(), input.end());
    int i = 0;
    for (std::string line: input) {
        int minusLen = UtilFunctions::split(line, " ")[1].length();
        std::sort(line.begin(), line.end() - minusLen);
        std::string alreadyChecked;
        int type = 0;
        for (char c: line) {
            if (alreadyChecked.find(c) == std::string::npos && type < 5) {
                int count = std::count(line.begin(), line.end() - minusLen, c);
                alreadyChecked += c;
                if (count == 5) {
                    type = 6; //5 equal
                    break;
                } else if (count == 4) {
                    type = 5; //4 equal
                    break;
                } else if (count == 3) {
                    if (type == 1) {
                        type = 4; //fullhouse
                    } else {
                        type = 3; //3 equal
                    }

                } else if (count == 2) {
                    if (type == 3) {
                        type = 4; //fullhouse
                    } else if (type == 1) {
                        type = 2; //2x2 equal
                    } else {
                        type = 1; //2 equal
                    }
                }
            }
        }
        sorted[type].push_back(input[i]);
        i++;
    }
    auto x = flatten(sorted);
    unsigned long long total = 0;
    for (int i = 0; i < x.size(); i++) {
        total += (i + 1) * std::stoll(UtilFunctions::split(x[i], " ")[1]);
    }
    std::cout << total << std::endl;
}
