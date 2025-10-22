
#include "include/device_menu.h"
#include <iostream>

int main() {

    int amount = 3;
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
        for (int i = 0; i < amount; i++) {
            std::cout << smartphone_obj[i] << std::endl;
        }

        std::cout << std::endl << "What device you want to change:\t";
        std::cin >> number_device;
        if (number_device < 0 || number_device >= amount) {
            std::cout << "max value is " << amount << " and min value is 0" << std::endl;
            continue;
        } else {
            edit_smartphone(smartphone_obj[number_device]);
        }

    } while (main_choice != -1);
}
