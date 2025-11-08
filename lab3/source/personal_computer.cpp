#include "../include/personal_computer.h"
#include <iomanip>

void PersonalComputer::print_header() const {
    ComputingMachine::print_header();
    std::cout << "Ports_count\tCase_form_factor\t";
}
String PersonalComputer::machine_type() const { return "Personal Computer"; }

void PersonalComputer::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set ports count\n4. Set form factor\n5. Show\n6. Full input (>>)\n0. Back\n> ";
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
            std::cout << "Ports: ";
            int p;
            std::cin >> p;
            set_ports_count(p);
        } else if (choice == 4) {
            std::cout << "Form factor: ";
            String s;
            std::cin >> s;
            set_case_form_factor(s);
        } else if (choice == 5) {
            std::cout << *this << std::endl;
        } else if (choice == 6) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 0);
}

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
    os << std::setw(11) << pc.ports_count << "\t";
    os << std::setw(16) << (pc.case_form_factor == "" ? "None" : pc.case_form_factor) << "\t";
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
