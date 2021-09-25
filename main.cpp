//
// Created by Connor Gamble on 9/25/21.
//

#include <iostream>
#include "AlgoList.h"

int main() {
    algo::AlgoList<int> list;

    list.push_front(3);
    list.push_front(5);

    list.display();
}