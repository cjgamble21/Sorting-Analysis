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
            T data;
            listNode* next;
            listNode* prev;

            explicit listNode(const T &arg, listNode *next = nullptr, listNode *prev = nullptr) : data(arg), next(next), prev(prev) {

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
    };
}
#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOLIST_H
