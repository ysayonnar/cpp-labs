#include "../include/portable_machine.h"

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
    os << "Battery capacity:\t" << machine.battery_capacity << std::endl;
    os << "Display type:\t" << (machine.display_type == "" ? "None" : machine.display_type) << std::endl;
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
