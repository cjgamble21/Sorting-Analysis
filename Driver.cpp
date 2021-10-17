//
// Created by Connor Gamble on 10/17/21.
//

#include "Driver.h"

void Driver::run() {
    fileName = "/Users/cjgamble/CLionProjects/21f-pa02-connor-gamble/Data";
    for (const auto& entry : std::filesystem::directory_iterator(fileName)) {
        int buffer;
        algo::AlgoVector<int> vector;
        std::ifstream file(entry.path());

        if (!file.is_open()) {
            std::cout << "Error" << std::endl;
        } else {

            while (!file.eof()) {
                file >> buffer;
                vector.push_back(buffer);
            }
        }

        algo::AlgoVector<int> toSort = vector;

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        algo::quick_sort(toSort.begin(), toSort.end());

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        std::cout << "File: " << entry.path() << std::endl;
        std::cout << "Time diff: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds" << std::endl;
//        std::cout << std::is_sorted(toSort.begin(), toSort.end()) << std::endl;
//        std::cout << std::endl;

        toSort = vector;
//        algo::quick_sort(toSort.begin(), toSort.end());


//        std::cout << std::is_sorted(toSort.begin(), toSort.end()) << std::endl;
//        std::cout << std::endl;

        toSort = vector;
//        algo::heap_sort(toSort.begin(), toSort.end());
//        std::cout << std::is_sorted(toSort.begin(), toSort.end()) << std::endl;
//        std::cout << std::endl;

    }
}