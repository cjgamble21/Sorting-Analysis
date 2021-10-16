//
// Created by Connor Gamble on 9/25/21.
//

#include <iostream>
#include "Algorithms.h"
#include "Containers/AlgoList.h"

bool compare(int a, int b) {
    return a < b;
}

int main() {
    algo::AlgoVector<int> vector;
    vector.push_back(3);
    vector.push_back(13);
    vector.push_back(6);
    vector.push_back(21);
    vector.push_back(1);
    vector.push_back(15);

//    algo::insertion_sort(vector.begin(), vector.end(), compare);

    algo::quick_sort(vector.begin(), vector.end() - 1, compare);

    for (int i : vector) {
        std::cout << i << std::endl;
    }
}