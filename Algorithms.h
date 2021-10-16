//
// Created by Connor Gamble on 10/16/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H

#include "Containers/AlgoVector.h"

namespace algo {

    template<class RAIterator>

        // insertion_sort takes two iterators, presumably for a vector
        /*
         * Code referenced for insertion_sort:
         * https://github.com/CS1342-Spring2021/Lecture-Materials/blob/master/Chapter09/insertion_sort.cpp
         */
        void insertion_sort(RAIterator begin, RAIterator end) {
            RAIterator forSwap;
            for (RAIterator itr = begin + 1; itr != end; itr++) {
                forSwap = itr;

                while (forSwap > begin && *forSwap < *(forSwap - 1)) {
                    std::swap(*forSwap, *(forSwap - 1));
                    --forSwap;
                }
            }
        }
}

#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H
