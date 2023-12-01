#include <iostream>
#include "SolveDay1.h"
#include <string>
#include <regex>

std::vector<std::string> SolveDay1::replacements = {"one", "two", "three", "four", "five", "six", "seven", "eight",
                                                    "nine"};

void SolveDay1::solve(const std::vector<std::string> &input) {
    int total = 0;
    for (std::string line: input) {
        line = preProcessLine(line);
        total += std::stoi(line);
    }
    std::cout << total << std::endl;
}


std::string SolveDay1::preProcessLine(const std::string &line) {
    std::string tmp = " ";
    for (char i: line) {
        if (i >= '0' && i <= '9') {
            tmp[0] = i;
            break; //found digit before word
        }
        tmp.push_back(i);
        int found = 0;
        for (int j = 0; j < replacements.size(); j++) {
            if (tmp.find(replacements[j]) != std::string::npos) {
                tmp[0] = std::to_string(j + 1)[0];
                found = 1;
                break; //found a word before digit
            }
        }
        if (found)
            break;
    }
    std::string end = " ";
    for (int i = line.length() - 1; i >= 0; i--) {
        if (line[i] >= '0' && line[i] <= '9') {
            end[0] = line[i];
            break; //found digit before word
        }
        end.insert(0, 1,line[i]);
        int found = 0;
        for (int j = 0; j < replacements.size(); j++) {
            if (end.find(replacements[j]) != std::string::npos) {
                end[0] = std::to_string(j + 1)[0];
                found = 1;
                break; //found a word before digit
            }
        }
        if (found)
            break;
    }
    std::string res = "aa";
    res[0] = tmp[0];
    res[1] = end[0];
    return res;
}


