#include "SolveDay03.h"
#include <vector>
#include <string>
#include <iostream>

std::string symbols = "*/+&%#@=$-";

void SolveDay03::solve(const std::vector<std::string> &input) {
    long total = 0;
    std::vector<std::string> nums;
    for (int i = 0; i < input.size(); i++) {
        std::string number;
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] >= '0' && input[i][j] <= '9') {
                number += input[i][j];
                if (number.find('Y') == std::string::npos) {
                    if (i != 0 && j != 0 && symbols.find(input[i - 1][j - 1]) != std::string::npos)                                   //top-left
                        number.insert(0, 1, 'Y');
                    if (i != 0 && symbols.find(input[i - 1][j]) != std::string::npos)                                                 //top-middle
                        number.insert(0, 1, 'Y');
                    if (i != 0 && j != input[i].length() - 1 && symbols.find(input[i - 1][j + 1]) != std::string::npos)               //top-right
                        number.insert(0, 1, 'Y');
                    if (j != 0 && symbols.find(input[i][j - 1]) != std::string::npos)                                                 //left
                        number.insert(0, 1, 'Y');
                    if (j != input[i].length() - 1 && symbols.find(input[i][j + 1]) != std::string::npos)                             //right
                        number.insert(0, 1, 'Y');
                    if (i != input.size() - 1 && j != 0 && symbols.find(input[i + 1][j - 1]) != std::string::npos)                     //bottom-left
                        number.insert(0, 1, 'Y');
                    if (i != input.size() - 1 && symbols.find(input[i + 1][j]) != std::string::npos)                                   //bottom-middle
                        number.insert(0, 1, 'Y');
                    if (i != input.size() - 1 && j != input[i].length() - 1 && symbols.find(input[i + 1][j + 1]) != std::string::npos)                                   //bottom-right
                        number.insert(0, 1, 'Y');
                }
            } else {
                if (number.length() > 0) {
                    if (number.find('Y') != std::string::npos) {
                        total += std::stoi(number.substr(1, number.length() - 1));
                    }
                    number = "";
                }
            }
        }
        if (number.find('Y') != std::string::npos) {
            total += std::stoi(number.substr(1, number.length() - 1));
        }
    }
    std::cout << total << std::endl;
}
