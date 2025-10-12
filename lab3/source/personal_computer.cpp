#include "../include/personal_computer.h"

String PersonalComputer::machine_type() const { return "Personal Computer"; }

int PersonalComputer::get_ports_count() const { return ports_count; }
String PersonalComputer::get_case_form_factor() const { return case_form_factor; }

void PersonalComputer::set_ports_count(int count) { ports_count = count; }
void PersonalComputer::set_case_form_factor(String form_factor) { case_form_factor = form_factor; }

PersonalComputer &PersonalComputer::operator=(const PersonalComputer &other) {
    if (this != &other) {
        ComputingMachine::operator=(other);
        ports_count = other.ports_count;
        case_form_factor = other.case_form_factor;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const PersonalComputer &pc) {
    os << static_cast<const ComputingMachine &>(pc);
    os << "Ports count:\t" << pc.ports_count << std::endl;
    os << "Case form factor:\t" << (pc.case_form_factor == "" ? "None" : pc.case_form_factor) << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, PersonalComputer &pc) {
    is >> static_cast<ComputingMachine &>(pc);
    std::cout << "Enter pc ports count:\t";
    is >> pc.ports_count;
    std::cout << "Enter case_form_factor:\t";
    is >> pc.case_form_factor;
    return is;
}
