template <class T>
List<T>::List() : head(nullptr), tail(nullptr) {}

template <class T>
List<T>::~List() {
    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr) {
        prev = curr;
        curr = curr->next;

        delete prev;
    }
}

template <class T>
void List<T>::add(T data) {
    if (!tail) {
        head = tail = new Node<T>(data);
    } else {
        tail = tail->next = new Node<T>(data);
    }
}

template <class T>
void List<T>::remove(T data) {
    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == head) {
        head = head->next;
    }

    if (curr == tail) {
        tail = prev;
    }

    if (prev) {
        prev->next = curr->next;
    }

    delete curr;
}

template <class T>
Iterator<T>* List<T>::getIterator() {
    return new Iterator<T>(this);
}