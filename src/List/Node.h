#pragma once

template <class T>
class Node {
public:
    Node* next;
    T data;
    
    Node(T data);
};

#include "Node.tpp"