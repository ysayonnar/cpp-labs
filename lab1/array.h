#ifndef ARRAY_H
#define ARRAY_H

class Array {
    int *arr;
    int length;

  public:
    Array();
    Array(int length);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    void fill();
    void print();
    int get_length();
    void set_length(int length);
    void sort();
    bool isEmpty();

    bool contains(int value);

    Array get_intersection(Array &b);
    Array get_union(Array &b);

  private:
    void quick_sort(int low, int high);
};

#endif
