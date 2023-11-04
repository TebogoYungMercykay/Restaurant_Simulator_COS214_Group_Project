#pragma once

#include "Node.h"

template <class T>
class List;

template <class T>
class Iterator {
private:
    List<T>* list;
    Node<T>* current;

public:
    Iterator(List<T>* list);
    void next();
    T getCurrent();
    bool isDone();
    void reset();
};

#include "Iterator.tpp"