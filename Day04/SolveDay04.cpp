#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <algorithm>
#include "SolveDay04.h"
#include "UtilFunctions.h"

#define PREFIX_LENGTH 5

void SolveDay04::solve(std::vector<std::string> input) {
    int total = 0;
    for (int i = 0; i < input.size(); i++) {
        int extraRounds = std::ranges::count(input[i], 'E');
        total += extraRounds;
        input[i] = input[i].substr(0, input[i].length() - extraRounds);
        for (int e = -1; e < extraRounds; e++) {
            int offset = 1;
            int colonPos = input[i].find(':');
            int gameId = std::stoi(input[i].substr(PREFIX_LENGTH, colonPos - PREFIX_LENGTH));
            std::vector<std::string> split = UtilFunctions::split(input[i].substr(colonPos + 2, input[i].length() - colonPos), "|");
            std::vector<std::string> cardNumbers = UtilFunctions::split(split[0], " ");
            std::vector<std::string> myNumbers = UtilFunctions::split(split[1], " ");
            for (std::string c: cardNumbers) {
                if (c != "")
                    for (std::string m: myNumbers) {
                        if (c == m) {
                            for (auto &j: input) {
                                if (j.find(std::format(" {}: ", gameId + offset)) != std::string::npos) {
                                    j += 'E';
                                    offset++;
                                    break;
                                }
                            }
                        }
                    }
            }
        }
    }
    std::cout << input.size() + total;
}