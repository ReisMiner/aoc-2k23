#pragma once

#include <string>
#include <vector>

class SolveDay1 {
public:
    static void solve(const std::vector<std::string> &input);

private:
    static std::string preProcessLine(const std::string& line);
    static std::vector<std::string> replacements;
};

