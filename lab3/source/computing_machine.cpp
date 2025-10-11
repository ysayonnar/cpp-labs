#include "../../string/string.h"
#include "../include/computing_machice.h"
#include <iostream>

String ComputingMachine::get_cpu() const { return cpu; }
String ComputingMachine::get_operating_system() const { return operating_system; }

void ComputingMachine::set_cpu(String c) { cpu = c; }
void ComputingMachine::set_operating_system(String os) { operating_system = os; }

ComputingMachine &ComputingMachine::operator=(const ComputingMachine &other) {
    if (this != &other) {
        cpu = other.cpu;
        operating_system = other.operating_system;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const ComputingMachine &machine) {
    os << "Computing machine with " << machine.cpu << " CPU and " << machine.operating_system << " operating system.";
    return os;
}

std::istream &operator>>(std::istream &is, ComputingMachine &machine) {
    is >> machine.cpu;
    is >> machine.operating_system;
    return is;
}