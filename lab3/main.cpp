
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
        smartphone_obj[0].print_header();
        for (int i = 0; i < amount; i++) {
            std::cout << smartphone_obj[i] << std::endl;
        }

        std::cout << "What device you want to change:\t";
        std::cin >> number_device;
        if (number_device < 0 || number_device >= amount) {
            std::cout << "max value is " << amount << " and min value is 0" << std::endl;
            continue;
        } else {
            edit_smartphone(smartphone_obj[number_device]);
        }

    } while (main_choice != -1);

    // PortableMachine portable_obj;
    // PersonalComputer pc_obj;
    // SmartPhone smartphone_obj;
    // Laptop laptop_obj;
    // Monoblock monoblock_obj;

    // int main_choice;
    // do {
    //     std::cout << "\nChoose type of device:\n1. PortableMachine\n2. PersonalComputer\n3. SmartPhone\n4. Laptop\n5. Monoblock\n0. Exit\n> ";
    //     std::cin >> main_choice;
    //     if (main_choice == 1) {
    //         edit_portable(portable_obj);
    //     } else if (main_choice == 2) {
    //         edit_pc(pc_obj);
    //     } else if (main_choice == 3) {
    //         edit_smartphone(smartphone_obj);
    //     } else if (main_choice == 4) {
    //         edit_laptop(laptop_obj);
    //     } else if (main_choice == 5) {
    //         edit_monoblock(monoblock_obj);
    //     }
    // } while (main_choice != 0);
    // return 0;
}
