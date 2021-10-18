//
// Created by Connor Gamble on 10/17/21.
//

#include "Driver.h"

void Driver::run() {
    fileName = "/Users/cjgamble/CLionProjects/21f-pa02-connor-gamble/Data/StringData";
    std::ofstream output("../PerformanceData/StringResultsData.txt");
    typedef std::chrono::steady_clock Clock;
    algo::AlgoVector<std::string> vector;
    algo::AlgoVector<std::string> toSort;
    Clock::time_point start;
    Clock::time_point end;
    std::chrono::duration<double> time{};

    for (const auto& entry : std::filesystem::directory_iterator(fileName)) {
        std::string buffer;
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

        output << "Insertion Sort time: " << time.count() << " seconds" << std::endl << std::endl;

        if (std::is_sorted(toSort.begin(), toSort.end())) {
            output << "Data set is fully sorted!" << std::endl << std::endl;
        }

        toSort = vector;

        start = Clock::now();

        algo::quick_sort(toSort.begin(), toSort.end());

        end = Clock::now();

        time = end - start;

        output << "Quick Sort time: " << time.count() << " seconds" << std::endl << std::endl;

        if (std::is_sorted(toSort.begin(), toSort.end())) {
            output << "Data set is fully sorted!" << std::endl << std::endl;
        }

        toSort = vector;

        start = Clock::now();

        algo::heap_sort(toSort.begin(), toSort.end());

        end = Clock::now();

        time = end - start;

        output << "Heap Sort time: " << time.count() << " seconds" << std::endl << std::endl;

        if (std::is_sorted(toSort.begin(), toSort.end())) {
            output << "Data set is fully sorted!" << std::endl << std::endl;
        }


        output << std::endl << std::endl;

        vector.clear();
        toSort.clear();

    }
}
