#include "../include/monoblock.h"

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
    os << "Built-in webcam: " << (mono.has_built_in_webcam ? "yes" : "no") << std::endl;
    os << "Screen size: " << mono.screen_size << std::endl;
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
