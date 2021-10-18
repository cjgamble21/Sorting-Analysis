//
// Created by Connor Gamble on 10/17/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_DRIVER_H
#define INC_21F_PA02_CONNOR_GAMBLE_DRIVER_H

#include <iostream>
#include "Algorithms.h"
#include <fstream>
#include <filesystem>
#include <chrono>

class Driver {
private:
    std::string fileName;

public:
    Driver() = default;
    Driver(std::string f) : fileName(f) {}
    void run();
};


#endif //INC_21F_PA02_CONNOR_GAMBLE_DRIVER_H
