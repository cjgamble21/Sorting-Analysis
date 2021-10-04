cmake_minimum_required(VERSION 3.20)
project(21f_pa02_connor_gamble)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Tests)
enable_testing()

add_executable(21f_pa02_connor_gamble
        main.cpp Containers/AlgoVector.h Containers/AlgoList.h Containers/AlgoAVLTree.h)
