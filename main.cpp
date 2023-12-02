#include <iostream>
#include "Day01/SolveDay1.h"
#include "InputReader.h"
#include "Day02/SolveDay2.h"

int main(int argc, char *argv[]) {
    int selection;
    if (argc < 2) {
        std::cout << "select day to run:";
        std::cin >> selection;
    } else {
        selection = atoi(argv[1]);
    }
    switch (selection) {
        case 1:
            SolveDay1::solve(InputReader::readInput("../Day01/input"));
            break;
        case 2:
            SolveDay2::solve(InputReader::readInput("../Day02/input"));
            break;
        default:
            std::cout << "exiting..." << std::endl;
    }

    return 0;
}
