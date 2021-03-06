//
// Created by Connor Gamble on 9/29/21.
//

#include <catch2/catch_all.hpp>
#include "../src/Containers/AlgoVector.h"

TEST_CASE("A vector object can be created") {
    algo::AlgoVector<std::string> vector;
}

TEST_CASE("A vector can have values pushed back") {
    algo::AlgoVector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    CHECK(vec.at(0) == 2);
    CHECK(vec.at(1) == 3);
}

TEST_CASE("A vector's .at() and operator[] functions return values at a given index") {
    algo::AlgoVector<int> vec;
    for (int i = 0; i < 20; i++) {
        vec.push_back(i);
    }

    CHECK(vec.at(0) == 0);
    CHECK(vec.at(9) == 9);
    CHECK(vec[8] == 8);
    CHECK(vec[12] == 12);
}

TEST_CASE("A vector can dynamically grows in size") {
    algo::AlgoVector<int> vec;
    for (int i = 0; i < 9; i++) {
        vec.push_back(i);
    }

    CHECK(vec.getCapacity() == 10);
    CHECK(vec.getSize() == 9);

    for (int i = 0; i < 5; i++) {
        vec.push_back(i);
    }

    CHECK(vec.getCapacity() == 100);
    CHECK(vec.getSize() == 14);
}

TEST_CASE("A vector's copy constructor can be invoked") {
    algo::AlgoVector<int> vec1;
    for (int i = 0; i < 20; i++) {
        vec1.push_back(i);
    }

    algo::AlgoVector<int> vec2 = vec1;

    for (int i = 0; i < 20; i++) {
        CHECK(vec2.at(i) == vec1.at(i));
    }
}

TEST_CASE("A vector's assignment operator can be invoked") {
    algo::AlgoVector<int> vec1;
    for (int i = 0; i < 15; i++) {
        vec1.push_back(i);
    }

    algo::AlgoVector<int> vec2;
    vec2 = vec1;

    for (int i = 0; i < 15; i++) {
        CHECK(vec2.at(i) == vec1.at(i));
    }
}

TEST_CASE("A vector's move constructor can be invoked") {
    algo::AlgoVector<int> vec1;
    for (int i = 0; i < 20; i++) {
        vec1.push_back(i);
    }

    algo::AlgoVector<int> vec2(std::move(vec1));

    for (int i = 0; i < 20; i++) {
        CHECK(vec2.at(i) == i);
    }

    CHECK(vec1.getSize() == 0);
    CHECK(vec1.getCapacity() == 10);
}

TEST_CASE("A vector's move assigment operator can be invoked") {
    algo::AlgoVector<int> vec1;
    for (int i = 0; i < 20; i++) {
        vec1.push_back(i);
    }

    algo::AlgoVector<int> vec2;

    vec2 = std::move(vec1);

    for (int i = 0; i < 20; i++) {
        CHECK(vec2.at(i) == i);
    }

    CHECK(vec1.getCapacity() == 10);
    CHECK(vec1.getSize() == 0);
}

TEST_CASE("Testing for iterators") {
    algo::AlgoVector<int> vec1;
    algo::AlgoVector<int> vec2;

    for (int i = 0; i < 15; i++) {
        vec1.push_back(i);
        vec2.push_back(i);
    }

    algo::AlgoVector<int>::Iterator itr1;
    algo::AlgoVector<int>::Iterator itr2;

    itr2 = &vec1.at(3);

    algo::AlgoVector<int>::Iterator itr3;
    itr2 = itr2 + 3;

    std::cout << *itr2 << std::endl;
    // itr2 should equal 6 here

    itr3 = itr2 - 2; // should equal 4

    int size = vec1.getSize();
    int diff = vec1.end() - vec1.begin();

    CHECK(itr3 < itr2);
    CHECK(itr3 <= itr2);
    CHECK(itr2 > itr3);
    CHECK(itr2 >= itr3);

    std::cout << size << std::endl;
    std::cout << diff << std::endl;

}