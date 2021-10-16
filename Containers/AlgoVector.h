//
// Created by Connor Gamble on 9/25/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H

#include <iostream>

namespace algo {

    template<typename T>
    class AlgoVector {
    private:
        T *data;
        int size;
        int capacity;

        // method which gives vector its dynamic sizing
        void reallocate() {
            capacity *= 10;
            T *temp = new T[capacity];
            for (int i = 0; i < size; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
        }

    public:
        // default constructor
        AlgoVector() : size(0), capacity(10) {
            data = new T[capacity];
        }

        // destructor
        ~AlgoVector() {
            std::cout << "Destructor called" << std::endl;
            delete[] data;
        }

        // copy constructor
        AlgoVector(const AlgoVector &rhs) {
            std::cout << "Copy constructor called" << std::endl;
            size = rhs.size;
            capacity = rhs.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = rhs.data[i];
            }
        }

        // assignment operator
        AlgoVector &operator=(const AlgoVector &rhs) {
            std::cout << "Assigment op called" << std::endl;
            if (this != &rhs) {
                delete[] data;
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
        AlgoVector(AlgoVector &&rhs) noexcept {
            size = rhs.size;
            capacity = rhs.capacity;
            data = rhs.data;

            rhs.size = 0;
            rhs.capacity = 10;
            rhs.data = new T[rhs.capacity];
        }

        // move assigment operator
        AlgoVector &operator=(AlgoVector &&rhs) noexcept {
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

        int getSize() {
            return size;
        }

        int getCapacity() {
            return capacity;
        }

        void push_back(const T &arg) {
            if (size == capacity) {
                reallocate();
            }
            data[size] = arg;
            size++;
        }

        T &at(int index) {
            if (index >= size) {
                throw std::out_of_range("Index is out of bounds.");
            }
            return data[index];
        }

        T &operator[](int index) {
            if (index >= size) {
                throw std::out_of_range("Index is out of bounds.");
            }
            return data[index];
        }

        class Iterator {
        private:
            T* ptr;

        public:
            Iterator() : ptr(nullptr) {}

            Iterator(const T& arg) {
                ptr = arg;
            }

            Iterator(const Iterator& arg) {
                ptr = arg.ptr;
            }

            Iterator& operator=(const Iterator& arg) {
                if (this != &arg) {
                    ptr = arg.ptr;
                }
                return *this;
            }

            T& operator*() const {
                return *ptr;
            }

            T* operator->() {
                return ptr;
            }

            Iterator& operator++() {
                ptr++;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            Iterator& operator--() {
                ptr--;
                return *this;
            }

            Iterator operator--(int) {
                Iterator temp = *this;
                --(*this);
                return temp;
            }

            Iterator operator+(int num) {
                Iterator toReturn;
                toReturn = ptr + num;
                return toReturn;
            }

            Iterator operator+(const Iterator& arg) {
                Iterator toReturn;
                toReturn = ptr + arg.ptr;
                return toReturn;
            }

            Iterator operator-(int num) {
                Iterator toReturn;
                toReturn = ptr - num;
                return toReturn;
            }

            Iterator operator-(const Iterator& arg) {
                Iterator toReturn;
                toReturn = ptr - arg.ptr;
                return toReturn;
            }

            bool operator<(const Iterator& rhs) {
                return ptr < rhs.ptr;
            }

            bool operator>(const Iterator& rhs) {
                return ptr > rhs.ptr;
            }

            bool operator<=(const Iterator& rhs) {
                return ptr <= rhs.ptr;
            }

            bool operator >=(const Iterator& rhs) {
                return ptr >= rhs.ptr;
            }

            bool operator==(const Iterator& rhs) {
                return ptr == rhs.ptr;
            }

            bool operator!=(const Iterator& rhs) {
                return ptr != rhs.ptr;
            }
        };

        Iterator begin() {
            return Iterator(&data[0]);
        }

        Iterator end() {
            return Iterator(&data[size]);
        }
    };
}


#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOVECTOR_H
