#include "SolveDay03.h"
#include <vector>
#include <string>
#include <iostream>

std::string symbols = "0123456789";

int collectNum(std::vector<std::string> input, int i, int j) {
    std::string num;
    int c = j;
    while (input[i][c] >= '0' && input[i][c] <= '9') {
        num.insert(0, 1, input[i][c]);
        c--;
    }
    j++;
    while (input[i][j] >= '0' && input[i][j] <= '9') {
        num += input[i][j];
        j++;
    }
    return std::stoi(num);
}

void setNumberInArray(int (&nums)[2], int num) {
    if (nums[0] != num && nums[1] != num) //does not account for the scenario if there are 2x the same number but its no duplicate (eg 100 above and 100 below the gear)
        if (nums[0] == 0) {
            if (nums[0] != num) {
                nums[0] = num;
            }
        } else if (nums[1] == 0) {
            if (nums[1] != num) {
                nums[1] = num;
            }
        }
}

void SolveDay03::solve(const std::vector<std::string> &input) {
    long total = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == '*') {
                int nums[2] = {0};
                if (i != 0 && j != 0 && symbols.find(input[i - 1][j - 1]) != std::string::npos) {
                    int num = collectNum(input, i - 1, j - 1);
                    setNumberInArray(nums, num);
                }
                if (i != 0 && symbols.find(input[i - 1][j]) != std::string::npos) {
                    int num = collectNum(input, i - 1, j);
                    setNumberInArray(nums, num);
                }
                if (i != 0 && j != input[i].length() - 1 && symbols.find(input[i - 1][j + 1]) != std::string::npos) {
                    int num = collectNum(input, i - 1, j + 1);
                    setNumberInArray(nums, num);
                }
                if (j != 0 && symbols.find(input[i][j - 1]) != std::string::npos) {
                    int num = collectNum(input, i, j - 1);
                    setNumberInArray(nums, num);
                }
                if (j != input[i].length() - 1 && symbols.find(input[i][j + 1]) != std::string::npos) {
                    int num = collectNum(input, i, j + 1);
                    setNumberInArray(nums, num);
                }
                if (i != input.size() - 1 && j != 0 && symbols.find(input[i + 1][j - 1]) != std::string::npos) {
                    int num = collectNum(input, i + 1, j - 1);
                    setNumberInArray(nums, num);
                }
                if (i != input.size() - 1 && symbols.find(input[i + 1][j]) != std::string::npos) {
                    int num = collectNum(input, i + 1, j);
                    setNumberInArray(nums, num);
                }
                if (i != input.size() - 1 && j != input[i].length() - 1 && symbols.find(input[i + 1][j + 1]) != std::string::npos) {
                    int num = collectNum(input, i + 1, j + 1);
                    setNumberInArray(nums, num);
                }
                total += nums[0] * nums[1];
            }
        }
    }
    std::cout << total << std::endl;
}
