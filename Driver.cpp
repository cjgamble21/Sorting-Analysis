//
// Created by Connor Gamble on 10/17/21.
//

#include "Driver.h"

void Driver::run() {
    fileName = "/Users/cjgamble/SMU/CS3353/PA02/StringData/Size1000";
    for (const auto& entry : std::filesystem::directory_iterator(fileName)) {
        std::string buffer;
        algo::AlgoVector<std::string> vector;
        std::ifstream file(entry.path());

        if (!file.is_open()) {
            std::cout << "Error" << std::endl;
        } else {

            while (!file.eof()) {
                file >> buffer;
                vector.push_back(buffer);
            }
        }

        algo::quick_sort(vector.begin(), vector.end());

    for (auto& i : vector) {
        std::cout << i << std::endl;
    }

//        std::cout << std::is_sorted(vector.begin(), vector.end());
    }
}