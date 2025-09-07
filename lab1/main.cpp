#include <iostream>
#include "array.h"

int main() {
    std::cout << "Creating first array..." << std::endl;
    Array arr1;
    arr1.fill();

    std::cout << std::endl << "Creating second array..." << std::endl;
    Array arr2;
    arr2.fill();

    Array intersection_arr = Array::get_intersection(arr1, arr2);
    std::cout << std::endl << "Intersection:\t";
    intersection_arr.print();

    Array union_arr = Array::get_union(arr1, arr2);
    std::cout << std::endl << "Union:\t";
    union_arr.print();
}