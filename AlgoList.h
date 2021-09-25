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


    };
}
#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOLIST_H
