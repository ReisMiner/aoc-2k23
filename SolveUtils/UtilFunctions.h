#pragma once

#include <string>
#include <vector>

class UtilFunctions {
public:
    static std::vector<std::string> split(std::string s, std::string delimiter);
    static std::vector<int> splitToInt(std::string s, std::string delimiter);
    static std::vector<unsigned long long> splitToUnsignedLongLong(std::string s, std::string delimiter);
    static std::vector<long long> splitToLongLong(std::string s, std::string delimiter);
};