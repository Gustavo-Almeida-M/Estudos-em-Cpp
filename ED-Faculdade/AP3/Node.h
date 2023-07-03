#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node 
{
    int value;
    Node *prev;
    Node *next;

    Node(const int& val, Node *prevPtr, Node *nextPtr)
    {
        value = val;
        prev = prevPtr;
        next = nextPtr;
    }

    ~Node() {
        std::cout << "removido: " << value << std::endl;
    }
};

#endif 
