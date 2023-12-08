#include <vector>
#include <string>
#include <iostream>
#include "SolveDay08.h"
#include <numeric>

std::vector<std::string> getBothValues(const std::string &input) {
    std::vector<std::string> split(2);
    split[0] = input.substr(7, 3);
    split[1] = input.substr(12, 3);
    return split;
}

unsigned long long lcmOfArray(std::vector<int> arr, int idx = 0) {
    if (idx == arr.size() - 1) {
        return arr[idx];
    }
    unsigned long long a = arr[idx];
    unsigned long long b = lcmOfArray(arr, idx + 1);
    return (a * b / std::gcd(a, b));
}

void SolveDay08::solve(std::vector<std::string> input) {
    std::vector<int> selectionOrder(input[0].length());
    for (int i = 0; i < input[0].length(); i++) {
        if (input[0][i] == 'L')
            selectionOrder[i] = 0;
        else
            selectionOrder[i] = 1;
    }
    std::vector<std::string> currents;
    for (int i = 2; i < input.size(); i++) {
        if (input[i][2] == 'A')
            currents.push_back(input[i].substr(0, 3));
    }
    int cursor = 0;
    std::vector<int> counts(currents.size(), 0);
    for (int c = 0; c < currents.size(); c++) {
        while (currents[c][2] != 'Z') {
            for (int i = 2; i < input.size(); i++) {
                if (input[i].substr(0, 3) == currents[c]) {
                    currents[c] = getBothValues(input[i])[selectionOrder[cursor]];
                    counts[c]++;
                    cursor = selectionOrder.size() == cursor + 1 ? 0 : cursor + 1;
                    break;
                }
            }
        }
    }

    std::cout << lcmOfArray(counts) << std::endl;
}
