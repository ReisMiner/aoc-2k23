#include <vector>
#include <string>
#include <iostream>
#include <format>
#include "SolveDay2.h"

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14
#define PREFIX_LENGTH 5

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


void SolveDay2::solve(const std::vector<std::string> &input) {
    int total = 0;
    for (const std::string &line: input) {
        int isGamePossible = 1;
        int colonPos = line.find(':');
        std::string gameId = line.substr(PREFIX_LENGTH, colonPos - PREFIX_LENGTH);
        std::string picks = line.substr(colonPos + 2, line.length() - colonPos);

        std::vector<std::string> res = split(picks, "; ");
        for (std::string pick: res) {
            std::vector<std::string> colors = split(pick, ", ");
            for (std::string col: colors) {
                std::vector<std::string> lastSplit = split(col, " ");
                if (lastSplit[1] == "red") {
                    if (std::stoi(lastSplit[0]) > RED_MAX)
                        isGamePossible = 0;
                }
                if (lastSplit[1] == "green") {
                    if (std::stoi(lastSplit[0]) > GREEN_MAX)
                        isGamePossible = 0;
                }
                if (lastSplit[1] == "blue") {
                    if (std::stoi(lastSplit[0]) > BLUE_MAX)
                        isGamePossible = 0;
                }
            }
        }
        if (isGamePossible)
            total += std::stoi(gameId);
    }
    std::cout << total << std::endl;
}

