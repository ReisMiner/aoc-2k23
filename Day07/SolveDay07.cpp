#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include "SolveDay07.h"
#include "UtilFunctions.h"

#define AMOUNT_OF_TYPES 7
//A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2
//E, D, C, 1, A, 9, 8, 7, 6, 5, 4, 3, 2

struct idfk {
    int count;
    char c;
};

std::vector<std::string> flatten(std::vector<std::vector<std::string>> &v) {
    std::vector<std::string> result;
    for (auto &sub_vector: v) {
        result.insert(result.end(), sub_vector.begin(), sub_vector.end());
    }
    return result;
}

std::string jokerToValue(std::string line) {
    if (line.find('1') == std::string::npos)
        return line;
    if (line == "11111") {
        return "EEEEE";
    }
    std::string res = line;
    std::vector<idfk> alreadyChecked;
    std::string aC;
    for (char c: line) {
        if (aC.find(c) == std::string::npos) {
            int count = std::count(line.begin(), line.end(), c);
            aC += c;
            alreadyChecked.push_back(idfk(count, c));
        }
    }
    size_t pos;
    std::sort(alreadyChecked.begin(), alreadyChecked.end(), [](idfk v1, idfk v2) { return v1.count > v2.count; });
    while ((pos = line.find('1')) != std::string::npos) {
        int count = 0;
        while (alreadyChecked[count].c == '1') {
            count++;
        }
        line[pos] = alreadyChecked[count].c;
    }
    return line;
}

void SolveDay07::solve(std::vector<std::string> input) {
    std::vector<std::vector<std::string>> sorted(AMOUNT_OF_TYPES);
    for (auto &item: input) {
        std::replace(item.begin(), item.end(), 'A', 'E');
        std::replace(item.begin(), item.end(), 'K', 'D');
        std::replace(item.begin(), item.end(), 'Q', 'C');
        std::replace(item.begin(), item.end(), 'J', '1');
        std::replace(item.begin(), item.end(), 'T', 'A');
    }
    std::sort(input.begin(), input.end());
    int i = 0;
    for (std::string line: input) {
        std::vector<std::string> splitted = UtilFunctions::split(line, " ");
        std::sort(splitted[0].begin(), splitted[0].end());
        splitted[0] = jokerToValue(splitted[0]);
        std::string alreadyChecked;
        int type = 0;
        for (char c: splitted[0]) {
            if (alreadyChecked.find(c) == std::string::npos && type < 5) {
                int count = std::count(splitted[0].begin(), splitted[0].end(), c);
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
    for (i = 0; i < x.size(); i++) {
        total += (i + 1) * std::stoll(UtilFunctions::split(x[i], " ")[1]);
    }
    std::cout << total << std::endl;
}
