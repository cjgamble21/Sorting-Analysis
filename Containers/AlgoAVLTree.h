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
        struct treeNode() {
            friend class Iterator;

            T data;
            treeNode* left;
            treeNode* right;
            int height;

            explicit treeNode(const T& arg, treeNode* left = nullptr, treeNode* right = nullptr) : data(arg), left(left), right(right) {}

            friend std::ostream& operator<<(std::ostream &stream, const listNode* &arg) {
                stream << arg->data;
                return stream;
            }
        }
        treeNode* root;
        int size;

        DSTree() : root(nullptr), size(0) {}

        DSTree(const DSTree& arg) {

        }

        void balance(Node*& t) {
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

        void rotateWithLeftChild(Node*& k2) {
            Node* k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right) + 1);
            k1->height = max(k2->height, height(k1->left)) + 1;
            k2 = k1;
        }

        void rotateWithRightChild(Node*& k2) {
            Node* k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(k2->height, height(k2->right)) + 1;
            k2 = k1;
        }

        void doubleWithLeftChild(Node*& k3) {
            rotateWithRightChild(k3->left);
            rotateWithLeftChild(k3);
        }

        void doubleWithRightChild(Node*& k3) {
            rotateWithLeftChild(k3->right);
            rotateWithRightChild(k3);
        }

        int max(int n1, int n2) {
            return (n1 > n2 ? n1 : n2);
        }

        void clearTree(Node*& c) {
            if (c != nullptr) {
                clearTree(c->left);
                clearTree(c->right);
                delete c;
            }
        }

        T& insert(Node*& c, const T& val) {
            if (c == nullptr) {
                c = new Node(val);
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

        T search(Node* c, const T& arg) {
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

        void printTree(Node* c) {
            if (c != nullptr) {
                printTree(c->left);
                std::cout << c->data << std::endl;
                printTree(c->right);
            }
        }

        bool contains(Node*&c, const T& arg) {
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
    };
}

#endif //INC_21F_PA02_CONNOR_GAMBLE_ALGOAVLTREE_H
