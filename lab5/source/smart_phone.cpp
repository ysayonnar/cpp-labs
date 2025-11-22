#include "../include/smart_phone.h"
#include <iomanip>

void SmartPhone::print_header() const {
    PortableMachine::print_header();
    std::cout << "Has_camera\tCharging_adapter_type\t";
}

String SmartPhone::machine_type() const { return String("SmartPhone"); }

void SmartPhone::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Set camera\n6. Set connector\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b;
            std::cin >> b;
            set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s;
            std::cin >> s;
            set_display_type(s);
        } else if (choice == 5) {
            std::cout << "Has camera (0/1): ";
            int c;
            std::cin >> c;
            set_has_camera(c);
        } else if (choice == 6) {
            std::cout << "Connector: ";
            String s;
            std::cin >> s;
            set_charging_connector_type(s);
        } else if (choice == 7) {
            std::cout << *this << std::endl;
        } else if (choice == 8) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}

bool SmartPhone::get_has_camera() const { return has_camera; }
String SmartPhone::get_charging_connector_type() const { return charging_connector_type; }

void SmartPhone::set_has_camera(bool value) { has_camera = value; }
void SmartPhone::set_charging_connector_type(String type) { charging_connector_type = type; }

SmartPhone &SmartPhone::operator=(const SmartPhone &other) {
    if (this != &other) {
        PortableMachine::operator=(other);
        has_camera = other.has_camera;
        charging_connector_type = other.charging_connector_type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SmartPhone &phone) {
    os << static_cast<const PortableMachine &>(phone);
    os << std::setw(10) << (phone.has_camera ? "yes" : "no") << "\t";
    os << std::setw(20) << (phone.charging_connector_type == "" ? "None" : phone.charging_connector_type) << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, SmartPhone &phone) {
    is >> static_cast<PortableMachine &>(phone);
    std::cout << "Enter 0 or 1 if phone has camera:\t";
    is >> phone.has_camera;
    std::cout << "Enter charging connector type:\t";
    is >> phone.charging_connector_type;
    return is;
}