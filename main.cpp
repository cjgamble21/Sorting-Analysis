//
// Created by Connor Gamble on 9/25/21.
//

#include <iostream>
#include "Algorithms.h"
#include "Containers/AlgoList.h"
#include "Driver.h"

bool compare(int a, int b) {
    return a < b;
}

int main() {
    algo::AlgoVector<int> vector;
//    int random{0};
//
//    for (int i = 0; i < 100; i++) {
//        random = rand() % 150;
//        vector.push_back(random);
//    }
    vector.push_back(3);
    vector.push_back(13);
    vector.push_back(6);
    vector.push_back(23);
    vector.push_back(6);
    vector.push_back(55);
    vector.push_back(2);
    vector.push_back(85);
    vector.push_back(60);
    vector.push_back(1);
    vector.push_back(15);
    vector.push_back(20);

    algo::heap_sort(vector.begin(), vector.end(), compare);
//    vector.heapsort(vector.getSize());

//    algo::quick_sort(vector.begin(), vector.end(), compare);
//
    for (int i : vector) {
        std::cout << i << std::endl;
    }
//    Driver d;
//    d.run();

}