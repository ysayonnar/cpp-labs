#include "../include/monoblock.h"
#include <iomanip>

void Monoblock::print_header() const { std::cout << "Proccesor\tOperatin_system\tPorts_count\tCase_form_factor\tHas_built_in_webcam\tScreen_size" << std::endl; }
String Monoblock::machine_type() const { return String("Monoblock"); }

bool Monoblock::get_has_built_in_webcam() const { return has_built_in_webcam; }
int Monoblock::get_screen_size() const { return screen_size; }

void Monoblock::set_has_built_in_webcam(bool value) { has_built_in_webcam = value; }
void Monoblock::set_screen_size(int size) { screen_size = size; }

Monoblock &Monoblock::operator=(const Monoblock &other) {
    if (this != &other) {
        PersonalComputer::operator=(other);
        has_built_in_webcam = other.has_built_in_webcam;
        screen_size = other.screen_size;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Monoblock &mono) {
    os << static_cast<const PersonalComputer &>(mono);
    os << std::setw(19) << (mono.has_built_in_webcam ? "yes" : "no") << "\t";
    os << std::setw(12) << mono.screen_size << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, Monoblock &mono) {
    is >> static_cast<PersonalComputer &>(mono);
    std::cout << "Enter 0 or 1 if monoblock has webcamera:\t";
    is >> mono.has_built_in_webcam;
    std::cout << "Enter screen size:\t";
    is >> mono.screen_size;
    return is;
}
