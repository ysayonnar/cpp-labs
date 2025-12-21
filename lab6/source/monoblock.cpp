#include "../include/monoblock.h"
#include "../include/input_utils.h"
#include "../include/serialization_utils.h"
#include <iomanip>
#include <sstream>

void Monoblock::print_header() const {
    PersonalComputer::print_header();
    std::cout << "Has_built_in_webcam\tScreen_size\t";
}
String Monoblock::machine_type() const { return String("Monoblock"); }

void Monoblock::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set ports count\n4. Set form factor\n5. Set webcam (0/1)\n6. Set screen size\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        choice = input_int(std::cin, 0, 8);
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
            std::cout << "Ports: ";
            int p = input_int(std::cin, 0, 1000);
            set_ports_count(p);
        } else if (choice == 4) {
            std::cout << "Form factor: ";
            String s = input_string_eng(std::cin);
            set_case_form_factor(s);
        } else if (choice == 5) {
            std::cout << "Has webcam (0/1): ";
            int w = input_int(std::cin, 0, 1);
            set_has_built_in_webcam(w);
        } else if (choice == 6) {
            std::cout << "Screen size: ";
            int sz = input_int(std::cin, 1, 300);
            set_screen_size(sz);
        } else if (choice == 7) {
            std::cout << *this << std::endl;
        } else if (choice == 8) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}

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
    mono.has_built_in_webcam = input_int(is, 0, 1);
    std::cout << "Enter screen size:\t";
    mono.screen_size = input_int(is, 1, 300);
    return is;
}

std::string Monoblock::text_header() const { return PersonalComputer::text_header() + std::string("Has_built_in_webcam\tScreen_size\t"); }

void Monoblock::to_text_row(std::ostream &os) const {
    PersonalComputer::to_text_row(os);
    os << (has_built_in_webcam ? 1 : 0) << '\t' << screen_size << '\t';
}

void Monoblock::from_text_row(const std::string &line) {
    PersonalComputer::from_text_row(line);
    std::istringstream iss(line);
    std::string token;
    for (int i = 0; i < 5; ++i)
        std::getline(iss, token, '\t');
    if (std::getline(iss, token, '\t'))
        has_built_in_webcam = (std::stoi(token) != 0);
    if (std::getline(iss, token, '\t'))
        screen_size = std::stoi(token);
}

void Monoblock::write_raw(std::ostream &os) const {
    PersonalComputer::write_raw(os);
    int wb = has_built_in_webcam ? 1 : 0;
    os.write(reinterpret_cast<const char *>(&wb), sizeof(wb));
    os.write(reinterpret_cast<const char *>(&screen_size), sizeof(screen_size));
}

void Monoblock::read_raw(std::istream &is) {
    PersonalComputer::read_raw(is);
    int wb = 0;
    is.read(reinterpret_cast<char *>(&wb), sizeof(wb));
    has_built_in_webcam = (wb != 0);
    is.read(reinterpret_cast<char *>(&screen_size), sizeof(screen_size));
}
