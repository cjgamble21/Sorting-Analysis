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

TEST_CASE("A list can be displayed") {
    algo::AlgoList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push_front(i*2);
    }

    list.display();

    // or you can display with a range based iterator loop
    for (int i : list) {
        std::cout << i << std::endl;
    }
}

TEST_CASE("A list can be copy constructed") {
    algo::AlgoList<int> list1;
    for (int i = 0; i < 15; i++) {
        list1.push_front(i);
    }

    algo::AlgoList<int> list2 = list1;

    CHECK(list1.getSize() == list2.getSize());

    algo::AlgoList<int>::Iterator itr1;
    algo::AlgoList<int>::Iterator itr2;
    itr2 = list2.begin();
    for (itr1 = list1.begin(); itr1 != list1.end(); ++itr1) {
        CHECK(*itr1 == *itr2);
        itr2++;
    }
}