#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <algorithm>
#include <cstring>
#include "SolveDay04.h"
#include "UtilFunctions.h"

#define PREFIX_LENGTH 5

void SolveDay04::solve(std::vector<std::string> input) {
    int total = 0;
    int size = input.size();
    int repeats[size];
    for (int &item: repeats) {
        item = 1;
    }
    for (int i = 0; i < input.size(); i++) {
        int offset = 1;
        int colonPos = input[i].find(':');
        int gameId = std::stoi(input[i].substr(PREFIX_LENGTH, colonPos - PREFIX_LENGTH));
        std::vector<std::string> split = UtilFunctions::split(input[i].substr(colonPos + 2, input[i].length() - colonPos), "|");
        std::vector<std::string> cardNumbers = UtilFunctions::split(split[0], " ");
        std::vector<std::string> myNumbers = UtilFunctions::split(split[1], " ");
        for (std::string c: cardNumbers) {
            if (c != "")
                for (std::string m: myNumbers) {
                    if (m != "" && c == m) {
                        for (auto &j: input) {
                            if (j.find(" " + std::to_string(gameId + offset) + ": ") != std::string::npos) {
                                repeats[i + offset] += repeats[i];
                                offset++;
                                break;
                            }
                        }
                    }
                }
        }
    }
    for (const auto &item: repeats) {
        total += item;
    }
    std::cout << total << std::endl;
}