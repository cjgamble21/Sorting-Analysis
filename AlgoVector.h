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
        AlgoVector(AlgoVector&& rhs) noexcept {
            size = rhs.size;
            capacity = rhs.capacity;
            data = rhs.data;

            rhs.size = 0;
            rhs.capacity = 10;
            rhs.data = new T[rhs.capacity];
        }

        // move assigment operator
        AlgoVector& operator=(AlgoVector&& rhs) noexcept {
            if (this != &rhs) {
                size = rhs.size;
                capacity = rhs.capacity;
                data = rhs.data;

                rhs.size = 0;
                rhs.capacity = 10;
                rhs.data = new T[rhs.capacity];
            }
            return *this;
        }

        void push_back(const T& arg) {
            if (size == capacity) {
                reallocate();
            }
            data[size] = arg;
            size++;
        }

        T& at(int index) {
            if (index >= size) {
                throw std::out_of_range("Index is out of bounds.");
            }
            return data[index];
        }

        T& operator[](int index) {
            if (index >= size) {
                throw std::out_of_range("Index is out of bounds.");
            }
            return data[index];
        }
    }
    };


#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H
