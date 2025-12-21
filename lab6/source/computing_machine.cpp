#include "../include/computing_machine.h"
#include "../../string/string.h"
#include "../include/input_utils.h"
#include "../include/serialization_utils.h"
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>

void ComputingMachine::print_header() const { std::cout << "Proccesor\tOperating_system\t"; }

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
    machine.cpu = input_string_eng(is);
    std::cout << "Enter name of operating system:\t";
    machine.operating_system = input_string_eng(is);
    return is;
}

std::string ComputingMachine::text_header() const { return std::string("Type\tProcessor\tOperating_system\t"); }

void ComputingMachine::to_text_row(std::ostream &os) const {
    // write type, cpu, os separated by tabs
    const char *cpu_c = (cpu == "") ? "" : cpu.c_str();
    const char *os_c = (operating_system == "") ? "" : operating_system.c_str();
    os << machine_type() << '\t' << cpu_c << '\t' << os_c << '\t';
}

void ComputingMachine::from_text_row(const std::string &line) {
    std::istringstream iss(line);
    std::string token;
    // type
    std::getline(iss, token, '\t');
    // cpu
    if (std::getline(iss, token, '\t'))
        cpu = String(token.c_str());
    // os
    if (std::getline(iss, token, '\t'))
        operating_system = String(token.c_str());
}

void ComputingMachine::write_raw(std::ostream &os) const {
    write_string_raw(os, cpu.c_str());
    write_string_raw(os, operating_system.c_str());
}

void ComputingMachine::read_raw(std::istream &is) {
    std::string s = read_string_raw(is);
    cpu = String(s.c_str());
    s = read_string_raw(is);
    operating_system = String(s.c_str());
}