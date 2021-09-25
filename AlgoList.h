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
        AlgoList() : head(nullptr), tail(nullptr), size(0) {

        }

        ~AlgoList() {
            listNode* toDelete = head;
            listNode* next;
            while (toDelete) {
                next = toDelete->next;
                delete toDelete;
                toDelete = next;
            }
        }

        AlgoList(const AlgoList<T>& arg) {
            size = arg.size;
            head = arg.head;
            tail = arg.tail;

            listNode* toCopy = head;
            for (int i = 0; i < size; i++) {
                push_front(toCopy->data);
                toCopy = toCopy->next;
            }
        }

        [[nodiscard]] int getSize() const {
            return size;
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
