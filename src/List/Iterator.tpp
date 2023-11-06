template <class T>
Iterator<T>::Iterator(List<T>* list) {
    this->list = list;
    current = list->head;
}

template <class T>
void Iterator<T>::next() {
    current = current->next;
}

template <class T>
T Iterator<T>::getCurrent() {
    return current->data;
}

template <class T>
bool Iterator<T>::isDone() {
    return !current;
}

template <class T>
void Iterator<T>::reset() {
    current = list->head;
}