//
// Created by Connor Gamble on 9/25/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGOLIST_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGOLIST_H

#include <iostream>

namespace algo {

    template <typename T>
    class AlgoList {
    private:
        struct listNode {
            friend class Iterator;

            T data;
            listNode* next;
            listNode* prev;

            explicit listNode(const T &arg, listNode *next = nullptr, listNode *prev = nullptr) : data(arg), next(next), prev(prev) {

            }
            friend std::ostream& operator<<(std::ostream &stream, const listNode* &arg) {
                stream << arg->data;
                return stream;
            }
        };
        listNode* head;
        listNode* tail;
        int size;

    public:

        // constructor
        AlgoList() : head(nullptr), tail(nullptr), size(0) {

        }

        // destructor
        ~AlgoList() {
            listNode* toDelete = head;
            listNode* next;
            while (toDelete) {
                next = toDelete->next;
                delete toDelete;
                toDelete = next;
            }
        }

        // copy constructor
        AlgoList(const AlgoList& arg) {
            size = arg.size;
            head = arg.head;
            tail = arg.tail;

            listNode* toCopy = head;
            for (int i = 0; i < size; i++) {
                push_front(toCopy->data);
                toCopy = toCopy->next;
            }
        }

        // assigment operator
        AlgoList& operator=(const AlgoList& arg) {
            if (this != &arg) {
                // clears out the invoking object's list
                ~AlgoList();

                size = arg.size;
                head = arg.head;
                tail = arg.tail;

                listNode *toCopy = head;
                for (int i = 0; i < size; i++) {
                    push_front(toCopy->data);
                    toCopy = toCopy->next;
                }
            }
            return *this;
        }

        // move constructor
        AlgoList(AlgoList&& arg) noexcept {
            size = arg.size;
            head = arg.head;
            tail = arg.tail;

            listNode* toCopy = head;
            for (int i = 0; i < size; i++) {
                push_front(toCopy->data);
                toCopy = toCopy->next;
            }

            arg.size = 0;
            arg.~AlgoList();
            arg.head = nullptr;
            arg.tail = nullptr;
        }

        // move assigment operator
        AlgoList& operator=(AlgoList&& arg)  noexcept {
            if (this != &arg) {
                ~AlgoList();

                size = arg.size;
                head = arg.head;
                tail = arg.tail;

                listNode* toCopy = head;
                for (int i = 0; i < size; i++) {
                    push_front(toCopy->data);
                    toCopy = toCopy->next;
                }

                arg.size = 0;
                arg.~AlgoList();
                arg.head = nullptr;
                arg.tail = nullptr;
            }
            return *this;
        }

        [[nodiscard]] int getSize() const {
            return size;
        }

        listNode* getHead() const {
            return head;
        }

        listNode* getTail() const {
            return tail;
        }

        void push_front(const T& arg) {
            auto newNode = new listNode(arg);
            if (size == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        void display() {
            listNode* toDisplay = head;
            for (int i = 0; i < size; i++) {
                std::cout << toDisplay->data << std::endl;
                toDisplay = toDisplay->next;
            }
        }

        // AlgoList iterator class
        class Iterator {
        private:
            listNode* ptr;

        public:

            Iterator() : ptr(nullptr) {}

            explicit Iterator(listNode* node) : ptr(node) {}

            ~Iterator() = default;

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
                return ptr->data;
            }

            T* operator->() {
                return ptr;
            }

            Iterator& operator++() {
                ptr = ptr->next;
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                ++(*this);
                return temp;
            }

            // operator-- is bidirectional iterator functionality, just thought I would add it
            Iterator& operator--() {
                ptr = ptr->prev;
                return *this;
            }

            Iterator operator--(int) {
                Iterator temp = *this;
                --(*this);
                return temp;
            }

            friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
                return lhs.ptr == rhs.ptr;
            }

            friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
                return lhs.ptr != rhs.ptr;
            }
        };

        Iterator begin() {
            return Iterator(head);
        }

        Iterator end() {
            return Iterator(nullptr);
        }
    };
}
#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOLIST_H
