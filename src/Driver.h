//
// Created by Connor Gamble on 10/17/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_DRIVER_H
#define INC_21F_PA02_CONNOR_GAMBLE_DRIVER_H

#include <iostream>
"aarch64-apple-darwin20/bits/c++config.h"
"bits/istream.tcc"
"bits/istream.tcc"
"bits/istream.tcc"
"aarch64-apple-darwin20/bits/c++config.h"
"bits/stringfwd.h"
"bits/postypes.h"
"bits/istream.tcc"
"aarch64-apple-darwin20/bits/c++config.h"
"bits/exception.h"
"bits/exception_ptr.h"
"bits/nested_exception.h"
"bits/char_traits.h"
"bits/localefwd.h"
"bits/ios_base.h"
"bits/istream.tcc"
"aarch64-apple-darwin20/bits/c++config.h"
"bits/istream.tcc"
"bits/localefwd.h"
"bits/ios_base.h"
"bits/cpp_type_traits.h"
"ext/type_traits.h"
"bits/streambuf.tcc"
"bits/basic_ios.h"
"bits/ostream_insert.h"
"bits/ostream.tcc"
"bits/istream.tcc"
"bits/istream.tcc"
"bits/istream.tcc"
"bits/istream.tcc"
#include "Algorithms.h"
#include <fstream>
"bits/fstream.tcc"
"bits/fstream.tcc"
"bits/codecvt.h"
"bits/fstream.tcc"
"aarch64-apple-darwin20/bits/c++config.h"
"stdio.h"
"aarch64-apple-darwin20/bits/basic_file.h"
"bits/fstream.tcc"
"bits/fstream.tcc"
#include <filesystem>
"bits/fs_fwd.h"
"bits/fs_path.h"
"bits/fs_dir.h"
"bits/fs_ops.h"
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
