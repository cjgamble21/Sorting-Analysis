//
// Created by Connor Gamble on 9/25/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H

#include <iostream>

namespace algo {

    template <typename T>
    class AlgoVector {
    private:
        T* data;
        int size;
        int capacity;

        // method which gives vector its dynamic sizing
        void reallocate() {
            capacity *= 10;
            T* temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            delete [] data;
            data = temp;
        }

    public:
        // default constructor
        AlgoVector() : size(0), capacity(10) {
            data = new T[capacity];
        }

        // destructor
        ~AlgoVector() {
            delete [] data;
        }

        // copy constructor
        AlgoVector(const AlgoVector& rhs) {
            size = rhs.size;
            capacity = rhs.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = rhs.data[i];
            }
        }

        // assignment operator
        AlgoVector& operator=(const AlgoVector& rhs) {
            if (this != &rhs) {
                delete [] data;
                size = rhs.size;
                capacity = rhs.capacity;
                data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        // move constructor
        AlgoVector(const AlgoVector&& rhs) {

        }

    };


#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H
