#include "../include/laptop.h"
#include "../include/input_utils.h"
#include <iomanip>

void Laptop::print_header() const {
    PortableMachine::print_header();
    std::cout << "Has_touchpad\tNum_usb_ports\t";
}
String Laptop::machine_type() const { return String("Laptop"); }

void Laptop::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Set touchpad (0/1)\n6. Set USB ports\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        choice = input_int(0, 8);
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
            std::cout << "Has touchpad (0/1): ";
            int t = input_int(0, 1);
            set_has_touchpad(t);
        } else if (choice == 6) {
            std::cout << "USB ports: ";
            int u = input_int(0, 100);
            set_num_usb_ports(u);
        } else if (choice == 7) {
            std::cout << *this << std::endl;
        } else if (choice == 8) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}

bool Laptop::get_has_touchpad() const { return has_touchpad; }
int Laptop::get_num_usb_ports() const { return num_usb_ports; }

void Laptop::set_has_touchpad(bool value) { has_touchpad = value; }
void Laptop::set_num_usb_ports(int num) { num_usb_ports = num; }

Laptop &Laptop::operator=(const Laptop &other) {
    if (this != &other) {
        PortableMachine::operator=(other);
        has_touchpad = other.has_touchpad;
        num_usb_ports = other.num_usb_ports;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Laptop &laptop) {
    os << static_cast<const PortableMachine &>(laptop);
    os << std::setw(12) << (laptop.has_touchpad ? "yes" : "no") << "\t";
    os << std::setw(13) << laptop.num_usb_ports << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, Laptop &laptop) {
    is >> static_cast<PortableMachine &>(laptop);
    std::cout << "Enter 0 or 1 if laptop has touchpad:\t";
    laptop.has_touchpad = input_int(0, 1);
    std::cout << "Enter number of usb-ports:\t";
    laptop.num_usb_ports = input_int(0, 100);
    return is;
}
