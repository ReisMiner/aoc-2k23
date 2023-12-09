#include <iostream>
#include <chrono>
#include "Day01/SolveDay1.h"
#include "InputReader.h"
#include "Day02/SolveDay2.h"
#include "Day03/SolveDay03.h"
#include "Day04/SolveDay04.h"
#include "Day05/SolveDay05.h"
#include "Day06/SolveDay06.h"
#include "Day07/SolveDay07.h"
#include "Day08/SolveDay08.h"
#include "Day09/SolveDay09.h"

int main(int argc, char *argv[]) {
    int selection;
    if (argc < 2) {
        std::cout << "select day to run:";
        std::cin >> selection;
    } else {
        selection = std::stoi(argv[1]);
    }
    auto startTime = std::chrono::high_resolution_clock::now();
    switch (selection) {
        case 1:
            SolveDay1::solve(InputReader::readInput("../Day01/input"));
            break;
        case 2:
            SolveDay2::solve(InputReader::readInput("../Day02/input"));
            break;
        case 3:
            SolveDay03::solve(InputReader::readInput("../Day03/input"));
            break;
        case 4:
            SolveDay04::solve(InputReader::readInput("../Day04/input"));
            break;
        case 5:
            SolveDay05::solve(InputReader::readInput("../Day05/input"));
            break;
        case 6:
            SolveDay06::solve(InputReader::readInput("../Day06/input"));
            break;
        case 7:
            SolveDay07::solve(InputReader::readInput("../Day07/input"));
            break;
        case 8:
            SolveDay08::solve(InputReader::readInput("../Day08/input"));
            break;
        case 9:
            SolveDay09::solve(InputReader::readInput("../Day09/input"));
            break;
        default:
            std::cout << "exiting..." << std::endl;
    }
    auto finishTime = std::chrono::high_resolution_clock::now();
    std::cout<<"Finish Time: "<< std::chrono::duration_cast<std::chrono::milliseconds >(finishTime-startTime).count() << "ms\n";

    return 0;
}
