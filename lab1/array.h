#ifndef ARRAY_H
#define ARRAY_H

class Array {
    int *arr;
    int length;

public:
    Array(int length);

    Array(const Array &other);

    ~Array();

    void fill();
    void print();
    int get_length();
    void set_length(int length);

    bool contains(int value);

    static Array get_intersection(Array& a, Array& b);
    static Array get_union(Array& a, Array& b);
};

#endif