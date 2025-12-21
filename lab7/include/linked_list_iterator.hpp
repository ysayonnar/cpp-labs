#ifndef LINKED_LIST_ITERATOR_H
#define LINKED_LIST_ITERATOR_H

template <typename T> class ListNode;

template <typename T> class LinkedListIterator {
  public:
    using value_type = T;
    using node_type = ListNode<T>;

    LinkedListIterator(node_type *n = nullptr) : node(n) {}

    T &operator*() const { return node->value; }
    T *operator->() const { return &node->value; }

    LinkedListIterator &operator++() {
        if (node)
            node = node->next;
        return *this;
    }
    LinkedListIterator operator++(int) {
        LinkedListIterator tmp = *this;
        ++*this;
        return tmp;
    }

    LinkedListIterator &operator--() {
        if (node)
            node = node->prev;
        return *this;
    }
    LinkedListIterator operator--(int) {
        LinkedListIterator tmp = *this;
        --*this;
        return tmp;
    }

    bool operator==(const LinkedListIterator &o) const { return node == o.node; }
    bool operator!=(const LinkedListIterator &o) const { return node != o.node; }

    ListNode<T> *get_node() const { return node; }

  private:
    ListNode<T> *node;
};

#endif
