#pragma once

template <class T>
class Node {
public:
    Node(T* data);
    Node* next;
    T* data;
};