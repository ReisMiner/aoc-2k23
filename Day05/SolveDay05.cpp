#include <vector>
#include <string>
#include <iostream>
#include <format>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include "SolveDay05.h"
#include "UtilFunctions.h"

#define START_FIRST_SEED 7
typedef unsigned long long ulong;

struct lookup {
    ulong min;
    ulong max;
    long long offset;
};

// seed -> soil -> fertilizer -> water -> light -> temperature -> humidity -> location

ulong resolve(ulong seed, std::vector<lookup> table[], int cursor = 0) {
    if (cursor == 7)
        return seed;
    for (const auto &recipe: table[cursor]) {
        if (recipe.min <= seed && recipe.max >= seed) {
            return resolve(seed + recipe.offset, table, cursor + 1);
        }
    }
    return resolve(seed, table, cursor + 1);

}

void SolveDay05::solve(std::vector<std::string> input) {
    std::vector<std::string> sSeeds = UtilFunctions::split(input[0].substr(START_FIRST_SEED, input[0].length() - START_FIRST_SEED), " ");
    std::vector<ulong> seeds;
    std::vector<lookup> table[7];
    for (const auto &item: sSeeds)
        seeds.push_back(std::stoll(item));
    int cursor = -2;
    for (const auto &line: input) {
        if (line.empty()) continue;
        if (line[0] >= 'a') {
            cursor++;
            continue;
        }
        std::vector<ulong> nums;
        for (const auto &item: UtilFunctions::split(line, " "))
            nums.push_back(std::stoll(item));
        table[cursor].push_back(lookup(nums[1], nums[1] - 1 + nums[2], nums[0] - nums[1]));
    }

    std::vector<ulong> results;

    for (int i = 0; i < seeds.size(); i += 2) {
        std::cout << i << std::endl;
        for (int j = 0; j < seeds[i + 1]; j++) {
            results.push_back(resolve(seeds[i] + j, table));
        }
    }
    std::cout << *std::ranges::min_element(results) << std::endl;
}