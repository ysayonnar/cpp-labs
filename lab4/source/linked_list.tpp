#include <iostream>

template <typename T> LinkedList<T>::~LinkedList() {
    ListNode<T> *current = head;
    while (current) {
        ListNode<T> *next = current->next;
        delete current;
        current = next;
    }
}

template <typename T> void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *node = new ListNode<T>(value);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    length++;
}

template <typename T> void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *node = new ListNode<T>(value);
    if (!head) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    length++;
}

template <typename T> bool LinkedList<T>::pop_back() {
    if (!tail)
        return false;
    ListNode<T> *temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    length--;
    return true;
}

template <typename T> bool LinkedList<T>::pop_front() {
    if (!head)
        return false;
    ListNode<T> *temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    length--;
    return true;
}

template <typename T> bool LinkedList<T>::erase(int index) {
    if (index < 0 || index >= length)
        return false;
    if (index == 0)
        return pop_front();
    if (index == length - 1)
        return pop_back();

    ListNode<T> *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->next;

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    length--;
    return true;
}

template <typename T> ListNode<T> *LinkedList<T>::find(const T &value) {
    for (ListNode<T> *cur = head; cur; cur = cur->next)
        if (cur->value == value)
            return cur;
    return nullptr;
}

template <typename T> template <typename Predicate> ListNode<T> *LinkedList<T>::find_if(Predicate pred) {
    for (ListNode<T> *cur = head; cur; cur = cur->next)
        if (pred(cur->value))
            return cur;
    return nullptr;
}

template <typename T> T &LinkedList<T>::operator[](int index) {
    ListNode<T> *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->value;
}

template <typename T> const T &LinkedList<T>::operator[](int index) const {
    ListNode<T> *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->value;
}

template <typename T> template <typename Less> void LinkedList<T>::sort(Less less) {
    if (length < 2)
        return;
    for (bool swapped = true; swapped;) {
        swapped = false;
        for (int i = 0; i < length - 1; i++) {
            if (less(i + 1, i)) {
                T temp = (*this)[i];
                (*this)[i] = (*this)[i + 1];
                (*this)[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

template <typename T> std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
    ListNode<T> *cur = list.head;
    while (cur) {
        os << cur->value;
        cur = cur->next;
    }
    return os;
}
