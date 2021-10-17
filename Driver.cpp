//
// Created by Connor Gamble on 10/17/21.
//

#include "Driver.h"

void Driver::run() {
    fileName = "/Users/cjgamble/CLionProjects/21f-pa02-connor-gamble/Data/IntegerData";
    std::ofstream output("IntegerResultsData.txt");
    typedef std::chrono::steady_clock Clock;
    algo::AlgoVector<int> vector;
    algo::AlgoVector<int> toSort;
    Clock::time_point start;
    Clock::time_point end;
    std::chrono::duration<double> time{};

    for (const auto& entry : std::filesystem::directory_iterator(fileName)) {
        int buffer;
//        std::cout << entry.path() << std::endl;
        std::ifstream file(entry.path());

        if (!file.is_open()) {
            std::cout << "Error" << std::endl;
        } else {

            while (!file.eof()) {
                file >> buffer;
                vector.push_back(buffer);
                toSort.push_back(buffer);
            }
        }

        output << "Data File: \n" << entry.path() << std::endl;

        start = Clock::now();

        algo::insertion_sort(toSort.begin(), toSort.end());

        end = Clock::now();
        time = end - start;

        output << "Insertion Sort time: " << time.count() << " milliseconds" << std::endl << std::endl;

        toSort = vector;

        start = Clock::now();

        algo::quick_sort(toSort.begin(), toSort.end());

        end = Clock::now();

        time = end - start;

        output << "Quick Sort time: " << time.count() << " milliseconds" << std::endl << std::endl;

        toSort = vector;

        start = Clock::now();

        algo::heap_sort(toSort.begin(), toSort.end());

        end = Clock::now();

        time = end - start;

        output << "Heap Sort time: " << time.count() << " milliseconds" << std::endl << std::endl;

        output << std::endl << std::endl;

        vector.clear();
        toSort.clear();

    }
}

void Driver::writeToFile(std::ofstream &output) {

}