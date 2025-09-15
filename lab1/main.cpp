#include "array.h"
#include <iostream>

void print_menu() {
    std::cout << "=~=~=~= OPTIONS =~=~=~=" << std::endl;
    std::cout << "1. Fill first array" << std::endl;
    std::cout << "2. Fill second array" << std::endl;
    std::cout << "3. Get intersection" << std::endl;
    std::cout << "4. Get union" << std::endl;
    std::cout << "5. Print first array" << std::endl;
    std::cout << "6. Print second array" << std::endl;
    std::cout << "7. Sort first array" << std::endl;
    std::cout << "8. Sort second array" << std::endl;
    std::cout << "0. EXIT" << std::endl << std::endl;
}

int main() {
    int option = 1;

    // TODO: убрать указатели
    Array *arr1 = nullptr;
    Array *arr2 = nullptr;

    while (option != 0) {
        print_menu();
        std::cout << "OPTION:\t";
        std::cin >> option;

        switch (option) {
        case 1: {
            int length1;
            std::cout << "Enter length:\t";
            std::cin >> length1;

            if (arr1 != nullptr) {
                delete arr1;
            }
            arr1 = new Array(length1);
            arr1->fill();
            break;
        }
        case 2: {
            int length2;
            std::cout << "Enter length:\t";
            std::cin >> length2;

            if (arr2 != nullptr) {
                delete arr2;
            }
            arr2 = new Array(length2);
            arr2->fill();
            break;
        }
        case 3: {
            if (arr1 == nullptr || arr2 == nullptr) {
                std::cout << "One of arrays is empty" << std::endl;
                break;
            }
            Array intersection_arr = arr1->get_intersection(*arr2);
            std::cout << std::endl << "Intersection:\t";
            intersection_arr.print();
            break;
        }
        case 4: {
            if (arr1 == nullptr || arr2 == nullptr) {
                std::cout << "One of arrays is empty" << std::endl;
                break;
            }
            Array union_arr = arr1->get_union(*arr2);
            std::cout << std::endl << "Union:\t";
            union_arr.print();
            break;
        }
        case 5: {
            if (arr1 == nullptr) {
                std::cout << std::endl << "Empty array!" << std::endl;
            } else {
                std::cout << std::endl << "Array:\t";
                arr1->print();
            }
            break;
        }
        case 6: {
            if (arr2 == nullptr) {
                std::cout << std::endl << "Empty array!" << std::endl;
            } else {
                std::cout << std::endl << "Array:\t";
                arr2->print();
            }
            break;
        }
        case 7: {
            if (arr1 == nullptr) {
                std::cout << "First array is empty" << std::endl;
                break;
            }
            arr1->sort();
            std::cout << "First array sorted!" << std::endl;
            break;
        }
        case 8: {
            if (arr2 == nullptr) {
                std::cout << "Second array is empty" << std::endl;
                break;
            }
            arr2->sort();
            std::cout << "Second array sorted!" << std::endl;
            break;
        }
        case 0: {
            delete arr1;
            delete arr2;
            break;
        }
        default:
            std::cout << "Wrong option!" << std::endl;
            break;
        }

        std::cout << std::endl;
    }
}
