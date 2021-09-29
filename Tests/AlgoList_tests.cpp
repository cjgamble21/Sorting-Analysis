//
// Created by Connor Gamble on 9/29/21.
//

#include <catch2/catch_all.hpp>
#include "../Containers/AlgoList.h"

TEST_CASE("A list can be instantiated") {
    algo::AlgoList<int> list;

    CHECK(list.getSize() == 0);
}