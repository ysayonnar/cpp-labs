#include "../include/computing_machine.h"
#include "../../string/string.h"
#include <iomanip>
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
    os << std::setw(10) << (machine.cpu == "" ? "None" : machine.cpu) << "\t";
    os << std::setw(16) << (machine.operating_system == "" ? "None" : machine.operating_system) << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, ComputingMachine &machine) {
    std::cout << "Enter name of CPU:\t";
    is >> machine.cpu;
    std::cout << "Enter name of operating system:\t";
    is >> machine.operating_system;
    return is;
}