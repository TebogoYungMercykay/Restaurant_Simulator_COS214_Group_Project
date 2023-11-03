#pragma once

#include "Node.h"

template <class T>
class Iterator {
private:
    Node<T>* start;
    Node<T>* current;

public:
    Iterator(Node<T>* head);
    void next();
    T getCurrent();
    bool isDone();
    void reset();
};