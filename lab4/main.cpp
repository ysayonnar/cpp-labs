#include "include/linked_list.hpp"
#include "include/smart_phone.h"
#include <iostream>

int main() {
    int amount = 3;
    std::cout << "Enter how many devices to create:\t";
    std::cin >> amount;

    LinkedList<SmartPhone> list;

    for (int i = 0; i < amount; i++) {
        std::cout << std::endl << "Enter object number " << i << std::endl;
        SmartPhone sm;
        std::cin >> sm;
        list.push_back(sm);
    }

    int main_choice;
    int number_device;
    do {
        std::cout << std::endl;
        list.head->value.print_header();
        std::cout << std::endl;

        ListNode<SmartPhone> *cur = list.head;

        while (cur != nullptr) {
            std::cout << cur->value << std::endl;
            cur = cur->next;
        }

        std::cout << std::endl << "What device you want to change:\t";
        std::cin >> number_device;
        if (number_device < 0 || number_device >= amount) {
            std::cout << "max value is " << amount << " and min value is 0" << std::endl;
            continue;
        } else {
            list[number_device].edit();
        }

    } while (main_choice != -1);
}
