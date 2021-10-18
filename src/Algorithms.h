//
// Created by Connor Gamble on 10/16/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H

#include "Containers/AlgoVector.h"
#include <algorithm>

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

    template<class RAIterator, class Compare>
    // compare class must define the behavior of the < operator
    void insertion_sort(RAIterator begin, RAIterator end, Compare comparator) {
        RAIterator forSwap;
        for (RAIterator itr = begin + 1; itr != end; itr++) {
            forSwap = itr;

            while (forSwap > begin && comparator(*forSwap, *(forSwap - 1))) {
                std::swap(*forSwap, *(forSwap - 1));
                --forSwap;
            }
        }
    }


    template<class RAIterator>
    /*
     * Code referenced for quick_sort:
     * https://github.com/jesyspa/linear-cpp/blob/master/Chapter%2009%20-%20Iterators/vector_algos.cpp
     */
    RAIterator partition(RAIterator begin, RAIterator end) {
        auto pivot = begin++;
        for (auto itr = begin; itr != end; itr++) {
            if (*itr < *pivot) {
                std::swap(*pivot, *itr);
                ++pivot;
                std::swap(*pivot, *itr);
            }
        }
        return pivot;
    }

    template<class RAIterator>
    void quick_sort(RAIterator begin, RAIterator end) {
        if (end - begin > 1) {
            auto partition_itr = partition(begin, end);
            quick_sort(begin, partition_itr);
            quick_sort(partition_itr + 1, end);
        }
    }

    template<class RAIterator, class Compare>
    // Compare should specify the behavior of the < operator
    RAIterator partition(RAIterator begin, RAIterator end, Compare comparator) {
        auto pivot = begin++;
        for (auto itr = begin; itr != end; itr++) {
            if (comparator(*itr, *pivot)) {
                std::swap(*pivot, *itr);
                ++pivot;
                std::swap(*pivot, *itr);
            }
        }
        return pivot;
    }

    template<class RAIterator, class Compare>
    void quick_sort(RAIterator begin, RAIterator end, Compare comparator) {
        if (end - begin > 1) {
            auto partition_itr = partition(begin, end, comparator);
            quick_sort(begin, partition_itr);
            quick_sort(partition_itr + 1, end);
        }
    }

    /*
     * Code referenced for heapsort:
     * https://gist.github.com/dmatveev/6008120
     */
    template<class RAIterator>
    void heap_sort(RAIterator begin, RAIterator end) {
        int size = end - begin;
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(begin, end, i, size);
        }

        for (int i = size - 1; i > 0; i--) {
            std::swap(*begin, *(begin + i));
            size -= 1;
            heapify(begin, end, 0, size);
        }
    }

    template<class RAIterator>
    void heapify(RAIterator begin, RAIterator end, int i, int heapSize) {
        int l = 2 * (i + 1) - 1;
        int r = 2 * (i + 1);

        int largest = i;

        if (l < heapSize && *(begin + i) < *(begin + l)) {
            largest = l;
        }

        if (r < heapSize && *(begin + largest) < *(begin + r)) {
            largest = r;
        }

        if (largest != i) {
            std::swap(*(begin + i), *(begin + largest));
            heapify(begin, end, largest, heapSize);
        }
    }

    template<class RAIterator, class Compare>
    void heap_sort(RAIterator begin, RAIterator end, Compare comparator) {
        int size = end - begin;
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(begin, end, i, size, comparator);
        }

        for (int i = size - 1; i > 0; i--) {
            std::swap(*begin, *(begin + i));
            size -= 1;
            heapify(begin, end, 0, size, comparator);
        }
    }

    template<class RAIterator, class Compare>
    void heapify(RAIterator begin, RAIterator end, int i, int heapSize, Compare comparator) {
        int l = 2 * (i + 1) - 1;
        int r = 2 * (i + 1);

        int largest = i;

        if (l < heapSize && comparator(*(begin + i), *(begin + l))) {
            largest = l;
        }

        if (r < heapSize && comparator(*(begin + largest), *(begin + r))) {
            largest = r;
        }

        if (largest != i) {
            std::swap(*(begin + i), *(begin + largest));
            heapify(begin, end, largest, heapSize, comparator);
        }
    }
}
#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGORITHMS_H
