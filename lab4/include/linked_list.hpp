#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <typename T> class LinkedList;

template <typename T> class ListNode {
  public:
    T value;
    ListNode<T> *prev = nullptr;
    ListNode<T> *next = nullptr;

    ListNode() {};
    ListNode(T value) : value(value) {};
    ~ListNode() = default;

    friend class LinkedList<T>;
};

template <typename T> class LinkedList {
  public:
    ListNode<T> *head = nullptr;
    ListNode<T> *tail = nullptr;
    int length = 0;

    LinkedList() {};
    ~LinkedList();

    void push_back(const T &value);
    void push_front(const T &value);
    bool pop_back();
    bool pop_front();
    bool erase(int index);

    ListNode<T> *find(const T &value);
    template <typename Predicate> ListNode<T> *find_if(Predicate pred);
    template <typename Less> void sort(Less less);

    T &operator[](int index);
    const T &operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list);
};

#include "../source/linked_list.tpp"

#endif
