#include <vector>
#include <string>
#include <iostream>
#include <format>
#include "SolveDay2.h"
#include "UtilFunctions.h"

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14
#define PREFIX_LENGTH 5




void SolveDay2::solve(const std::vector<std::string> &input) {
    int total = 0;
    for (const std::string &line: input) {
        int minColors[3] = {0};
        int colonPos = line.find(':');
        std::string gameId = line.substr(PREFIX_LENGTH, colonPos - PREFIX_LENGTH);
        std::string picks = line.substr(colonPos + 2, line.length() - colonPos);

        std::vector<std::string> res = UtilFunctions::split(picks, "; ");
        for (std::string pick: res) {
            std::vector<std::string> colors =  UtilFunctions::split(pick, ", ");
            for (std::string col: colors) {
                std::vector<std::string> lastSplit =  UtilFunctions::split(col, " ");
                int num = std::stoi(lastSplit[0]);
                if (lastSplit[1] == "red") {
                    if (num > minColors[0])
                        minColors[0] = num;
                }
                if (lastSplit[1] == "green") {
                    if (num > minColors[1])
                        minColors[1] = num;
                }
                if (lastSplit[1] == "blue") {
                    if (num > minColors[2])
                        minColors[2] = num;
                }
            }
        }

        total += minColors[0] * minColors[1] * minColors[2];
    }
    std::cout << total << std::endl;
}

