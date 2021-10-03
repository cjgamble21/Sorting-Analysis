//
// Created by Connor Gamble on 9/29/21.
//

#include <catch2/catch_all.hpp>
#include "../Containers/AlgoList.h"

TEST_CASE("A list can be instantiated") {
    algo::AlgoList<int> list;

    CHECK(list.getSize() == 0);
    CHECK(list.getHead() == nullptr);
}

TEST_CASE("A list can have objects added to the front") {
    algo::AlgoList<int> list;
    list.push_front(3);
    list.push_front(5);
    list.push_front(10);

    auto head = list.getHead();
    CHECK(head->data == 10);
    head = head->next;
    CHECK(head->data == 5);
    head = head->next;
    CHECK(head->data == 3);
}