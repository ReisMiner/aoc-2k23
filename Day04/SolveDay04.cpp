#include <vector>
#include <string>
#include <iostream>
#include "SolveDay04.h"
#include "UtilFunctions.h"

void SolveDay04::solve(const std::vector<std::string> &input) {
    int total = 0;
    for (const std::string &line: input) {
        int gameScore = 0;
        int colonPos = line.find(':');
        std::vector<std::string> split = UtilFunctions::split(line.substr(colonPos + 2, line.length() - colonPos), "|");
        std::vector<std::string> cardNumbers = UtilFunctions::split(split[0], " ");
        std::vector<std::string> myNumbers = UtilFunctions::split(split[1], " ");
        for (std::string c: cardNumbers) {
            if (c != "")
                for (std::string m: myNumbers) {
                    if (c == m) {
                        if (gameScore == 0)
                            gameScore = 1;
                        else
                            gameScore *= 2;
                    }
                }
        }
        total += gameScore;
    }
    std::cout << total;
}