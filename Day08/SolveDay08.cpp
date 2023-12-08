#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "SolveDay08.h"
#include "UtilFunctions.h"

#define WIN_STRING "ZZZ"
#define START_STRING "AAA"

std::vector<std::string> getBothValues(const std::string &input) {
    std::vector<std::string> split(2);
    split[0] = input.substr(7, 3);
    split[1] = input.substr(12, 3);
    return split;

}

void SolveDay08::solve(std::vector<std::string> input) {
    std::vector<int> selectionOrder(input[0].length());
    for (int i = 0; i < input[0].length(); i++) {
        if (input[0][i] == 'L')
            selectionOrder[i] = 0;
        else
            selectionOrder[i] = 1;
    }
    std::string current = START_STRING;
    int count = 0, cursor = 0;
    while (current != WIN_STRING) {
        for (int i = 2; i < input.size(); i++) {
            if (input[i].substr(0, 3) == current) {
                current = getBothValues(input[i])[selectionOrder[cursor]];
                count++;
                cursor = selectionOrder.size() == cursor + 1 ? 0 : cursor + 1;
                break;
            }
        }
    }
    std::cout << count << std::endl;
}
