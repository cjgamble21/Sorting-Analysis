//
// Created by Connor Gamble on 10/3/21.
//

#include <catch2/catch_all.hpp>
#include "../Containers/AlgoAVLTree.h"

TEST_CASE("A tree object can be instantiated") {
    algo::AlgoAVLTree<int> tree;
}

TEST_CASE("A tree can have values inserted") {
    algo::AlgoAVLTree<int> tree;
    for (int i = 0; i < 10; i++) {
        tree.insert(i);
    }
}
