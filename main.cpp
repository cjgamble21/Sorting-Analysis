//
// Created by Connor Gamble on 9/25/21.
//

#include <iostream>
#include "Containers/AlgoList.h"

int main() {
    algo::AlgoList<int> list;

    list.push_front(3);
    list.push_front(5);

    algo::AlgoList<int>::Iterator itr;

    itr = list.begin();
    std::cout << *itr << std::endl;

    algo::AlgoList<int>::Iterator itr2;

    itr2 = list.begin();

    if (itr == itr2) {
        std::cout << "Success!" << std::endl;
    }

    for (int i : list) {
        std::cout << i << std::endl;
    }

}