// Implementations for various LinkedList algorithms using the iterator

#include <iostream>

template <typename T> ListNode<T> *LinkedList<T>::find(const T &value) {
    for (LinkedListIterator<T> it = begin(); it != end(); ++it)
        if (*it == value)
            return it.get_node();
    return nullptr;
}

template <typename T> template <typename Predicate> ListNode<T> *LinkedList<T>::find_if(Predicate pred) {
    for (LinkedListIterator<T> it = begin(); it != end(); ++it)
        if (pred(*it))
            return it.get_node();
    return nullptr;
}

template <typename T> T &LinkedList<T>::operator[](int index) {
    LinkedListIterator<T> it = begin();
    for (int i = 0; i < index; ++i)
        ++it;
    return *it;
}

template <typename T> const T &LinkedList<T>::operator[](int index) const {
    ListNode<T> *cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->next;
    return cur->value;
}

template <typename T> bool LinkedList<T>::erase(int index) {
    if (index < 0 || index >= length)
        return false;
    if (index == 0)
        return pop_front();
    if (index == length - 1)
        return pop_back();

    LinkedListIterator<T> it = begin();
    for (int i = 0; i < index; ++i)
        ++it;
    ListNode<T> *cur = it.get_node();

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    length--;
    return true;
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

// begin / end implementations
template <typename T> LinkedListIterator<T> LinkedList<T>::begin() { return LinkedListIterator<T>(head); }

template <typename T> LinkedListIterator<T> LinkedList<T>::end() { return LinkedListIterator<T>(nullptr); }
