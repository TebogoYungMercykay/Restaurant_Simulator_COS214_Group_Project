#pragma once 

#include "Node.h"
#include "Iterator.h"

template <class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    List();
    ~List();
    void add(T* data);
    void remove(T* data);
    Iterator<T>* getIterator();
};