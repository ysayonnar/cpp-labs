#include "../include/portable_machine.h"
#include "../include/input_utils.h"
#include "../include/serialization_utils.h"
#include <cstdint>
#include <iomanip>
#include <sstream>

void PortableMachine::print_header() const {
    ComputingMachine::print_header();
    std::cout << "Battery_capacity\tDisplay_type\t";
}
String PortableMachine::machine_type() const { return "Portable Machine"; }

void PortableMachine::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Show\n6. Full input (>>)\n0. Back\n> ";
        choice = input_int(std::cin, 0, 6);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 1) {
            std::cout << "CPU: ";
            String s = input_string_eng(std::cin);
            set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s = input_string_eng(std::cin);
            set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b = input_int(std::cin, 1, 90000);
            set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s = input_string_eng(std::cin);
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
    machine.battery_capacity = input_int(is, 1, 90000);
    std::cout << "Enter display type:\t";
    machine.display_type = input_string_eng(is);
    return is;
}

std::string PortableMachine::text_header() const { return ComputingMachine::text_header() + std::string("Battery\tDisplay\t"); }

void PortableMachine::to_text_row(std::ostream &os) const {
    ComputingMachine::to_text_row(os);
    const char *disp = (display_type == "") ? "" : display_type.c_str();
    os << battery_capacity << '\t' << disp << '\t';
}

void PortableMachine::from_text_row(const std::string &line) {
    // parse base first
    ComputingMachine::from_text_row(line);
    // we need to extract battery and display from the line; split by tabs
    std::istringstream iss(line);
    std::string token;
    // skip type,cpu,os
    std::getline(iss, token, '\t');
    std::getline(iss, token, '\t');
    std::getline(iss, token, '\t');
    // battery
    if (std::getline(iss, token, '\t'))
        battery_capacity = std::stoi(token);
    if (std::getline(iss, token, '\t'))
        display_type = String(token.c_str());
}

void PortableMachine::write_raw(std::ostream &os) const {
    ComputingMachine::write_raw(os);
    os.write(reinterpret_cast<const char *>(&battery_capacity), sizeof(battery_capacity));
    write_string_raw(os, display_type.c_str());
}

void PortableMachine::read_raw(std::istream &is) {
    ComputingMachine::read_raw(is);
    is.read(reinterpret_cast<char *>(&battery_capacity), sizeof(battery_capacity));
    std::string s = read_string_raw(is);
    display_type = String(s.c_str());
}
