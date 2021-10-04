//
// Created by Connor Gamble on 10/3/21.
//

#ifndef INC_21F_PA02_CONNOR_GAMBLE_ALGOAVLTREE_H
#define INC_21F_PA02_CONNOR_GAMBLE_ALGOAVLTREE_H

#include <iostream>

namespace algo {

    template<typename T>
    class AlgoAVLTree {
    private:
        struct treeNode {
            friend class Iterator;

            T data;
            treeNode* left;
            treeNode* right;
            int height;

            explicit treeNode(const T& arg, treeNode* left = nullptr, treeNode* right = nullptr) : data(arg), left(left), right(right) {}

            friend std::ostream& operator<<(std::ostream &stream, const treeNode* &arg) {
                stream << arg->data;
                return stream;
            }
        };
        treeNode* root;
        int size;

        // keeping the memory management methods in the private section to keep user from invoking them
        AlgoAVLTree(const AlgoAVLTree& arg) = default;

        AlgoAVLTree& operator=(const AlgoAVLTree& arg) = default;

        void balance(treeNode*& t) {
            if (t == nullptr) {
                return;
            }
            if (height(t->left) - height(t->right) > 1) {
                if(height(t->left->left) >= height(t->left->right)) {
                    rotateWithLeftChild(t);
                } else {
                    doubleWithLeftChild(t);
                }
            } else if (height(t->right) - height(t->left) > 1) {
                if (height(t->right->right) >= height(t->right->left)) {
                    rotateWithRightChild(t);
                } else {
                    doubleWithRightChild(t);
                }
            }
            t->height = max(height(t->left), height(t->right)) + 1;
        }

        void rotateWithLeftChild(treeNode*& k2) {
            treeNode* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right) + 1);
            k1->height = max(k2->height, height(k1->left)) + 1;
            k2 = k1;
        }

        void rotateWithRightChild(treeNode*& k2) {
            treeNode* k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(k2->height, height(k2->right)) + 1;
            k2 = k1;
        }

        void doubleWithLeftChild(treeNode*& k3) {
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        void doubleWithRightChild(treeNode*& k3) {
            rotateWithLeftChild(k3->right);
            rotateWithRightChild(k3);
        }

        int max(int n1, int n2) {
            return (n1 > n2 ? n1 : n2);
        }

        void clearTree(treeNode*& c) {
            if (c != nullptr) {
                clearTree(c->left);
                clearTree(c->right);
                delete c;
            }
        }

        T& insert(treeNode*& c, const T& val) {
            if (c == nullptr) {
                c = new treeNode(val);
                size++;
            } else if (val < c->data) {
                balance(c);
                return insert(c->left, val);
            } else if (c->data < val) {
                balance(c);
                return insert(c->right, val);
            }
            return c->data;
        }

        T search(treeNode* c, const T& arg) {
            if (c == nullptr) {
                std::cout << "Object not found" << std::endl;
                return T();
            } else if (arg < c->data) {
                return search(c->left, arg);
            } else if (c->data < arg) {
                return search(c->right, arg);
            } else {
                return c->data;
            }
        }

        void printTree(treeNode* c) {
            if (c != nullptr) {
                printTree(c->left);
                std::cout << c->data << std::endl;
                printTree(c->right);
            }
        }

        bool contains(treeNode*&c, const T& arg) {
            if (c == nullptr) {
                return false;
            } else if (arg < c->data) {
                contains(c->left, arg);
            } else if (c->data < arg) {
                contains(c->right, arg);
            } else {
                return true;
            }
        }

    public:
        AlgoAVLTree() : root(nullptr), size(0) {}

        ~AlgoAVLTree() {
            clearTree(root);
        }

        T& insert(const T& val) {
            return insert(root, val);
        }

        int height(treeNode* t) const {
            return (t == nullptr ? -1 : t->height);
        }

        void display() {
            printTree(root);
        }

        bool contains(const T& arg) {
            return contains(root, arg);
        }

        T search(const T& arg) {
            return search(root, arg);
        }

        void clear() {
            clearTree(root);
        }


        int getSize() const {
            return size;
        }

        class Iterator {
        private:
            treeNode ptr;

        public:

            Iterator() : ptr(nullptr) {}

            explicit Iterator(treeNode* node) : ptr(node) {}

            ~Iterator() = default;

            Iterator(const Iterator& arg) {
                ptr = arg.ptr;
            }

            T& operator*() {
                return *ptr;
            }

            T* operator->() {
                return ptr;
            }

            Iterator& operator++() {

            }
        };
    };
}

#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOAVLTREE_H
