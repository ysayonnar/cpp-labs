#include "../include/portable_machine.h"
#include "../include/input_utils.h"
#include <iomanip>

void PortableMachine::print_header() const {
    ComputingMachine::print_header();
    std::cout << "Battery_capacity\tDisplay_type\t";
}
String PortableMachine::machine_type() const { return "Portable Machine"; }

void PortableMachine::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Show\n6. Full input (>>)\n0. Back\n> ";
        choice = input_int(0, 6);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) {
            std::cout << "CPU: ";
            String s = input_string_eng(-1, -1);
            set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s = input_string_eng(-1, -1);
            set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b = input_int(1, 90000);
            set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s = input_string_eng(1, 20);
            set_display_type(s);
        } else if (choice == 5) {
            std::cout << *this << std::endl;
        } else if (choice == 6) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}

int PortableMachine::get_battery_capacity() const { return battery_capacity; }
String PortableMachine::get_display_type() const { return display_type; }

void PortableMachine::set_battery_capacity(int capacity) { battery_capacity = capacity; }
void PortableMachine::set_display_type(String type) { display_type = type; }

PortableMachine &PortableMachine::operator=(const PortableMachine &other) {
    if (this != &other) {
        ComputingMachine::operator=(other);
        battery_capacity = other.battery_capacity;
        display_type = other.display_type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PortableMachine &machine) {
    os << static_cast<const ComputingMachine &>(machine);
    os << std::setw(16) << machine.battery_capacity << "\t";
    os << std::setw(12) << (machine.display_type == "" ? "None" : machine.display_type) << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, PortableMachine &machine) {
    is >> static_cast<ComputingMachine &>(machine);
    std::cout << "Enter battery capacity:\t";
    machine.battery_capacity = input_int(1, 90000);
    std::cout << "Enter display type:\t";
    machine.display_type = input_string_eng(1, 20);
    return is;
}
