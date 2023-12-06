#pragma once

#include <string>
#include <vector>

class UtilFunctions {
public:
    static std::vector<std::string> split(std::string s, std::string delimiter);
    static std::vector<int> splitToInt(std::string s, std::string delimiter);
};