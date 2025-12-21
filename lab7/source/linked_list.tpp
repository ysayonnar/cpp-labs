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

// Algorithm implementations moved to include/linked_list_algorithm.tpp
#include "../include/linked_list_algorithm.hpp"
