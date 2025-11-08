#include "include/smart_phone.h"
#include <iostream>

int main() {
    int amount = 3;
    std::cout << "Enter how many devices to create:\t";
    std::cin >> amount;

    SmartPhone smartphone_obj[amount];
    for (int i = 0; i < amount; i++) {
        std::cout << std::endl << "Enter object number " << i << std::endl;
        std::cin >> smartphone_obj[i];
    }

    int main_choice;
    int number_device;
    do {
        std::cout << std::endl;
        smartphone_obj[0].print_header();
        std::cout << std::endl;

        for (int i = 0; i < amount; i++) {
            std::cout << smartphone_obj[i] << std::endl;
        }

        std::cout << std::endl << "What device you want to change:\t";
        std::cin >> number_device;
        if (number_device < 0 || number_device >= amount) {
            std::cout << "max value is " << amount << " and min value is 0" << std::endl;
            continue;
        } else {
            smartphone_obj[number_device].edit();
        }

    } while (main_choice != -1);
}
