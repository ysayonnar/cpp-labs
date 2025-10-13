#include "../include/portable_machine.h"
#include <iomanip>

void PortableMachine::print_header() const { std::cout << "Proccesor\tOperating_system\tBattery_capacity\tDisplay_type" << std::endl; }
String PortableMachine::machine_type() const { return "Portable Machine"; }

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
    is >> machine.battery_capacity;
    std::cout << "Enter display type:\t";
    is >> machine.display_type;
    return is;
}
