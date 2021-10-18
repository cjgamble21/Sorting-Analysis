cmake_minimum_required(VERSION 3.20)
project(21f_pa02_connor_gamble)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Tests)
enable_testing()

add_executable(21f_pa02_connor_gamble
        src/main.cpp src/Containers/AlgoVector.h src/Containers/AlgoList.h src/Containers/AlgoAVLTree.h src/Algorithms.h src/Driver.h src/Driver.cpp)

