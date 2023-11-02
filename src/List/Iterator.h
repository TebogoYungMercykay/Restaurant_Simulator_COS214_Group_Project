#pragma once

#include "Node.h"

template <class T>
class Iterator {
private:
    Node<T>* current;

public:
    Iterator(Node<T>* head);
    void next();
    T* getCurrent();
    bool isDone();
};