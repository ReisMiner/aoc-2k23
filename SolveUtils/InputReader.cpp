#include <fstream>
#include "InputReader.h"

std::vector<std::string> InputReader::readInput(const std::string &path) {
    std::vector<std::string> inputLines;
    std::ifstream input(path, std::ios::in);

    std::string line;
    while (std::getline(input, line))
        inputLines.push_back(line);
    return inputLines;
}

