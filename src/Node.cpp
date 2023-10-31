#include "Node.h"

template <class T>
Node<T>::Node(T* data) : next(NULL), data(data) {}