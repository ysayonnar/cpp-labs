#include "../include/laptop.h"
#include <iomanip>

void Laptop::print_header() const { std::cout << "Proccesor\tOperating_system\tBattery_capacity\tDisplay_type\tHas_touchpad\tNum_usb_ports" << std::endl; }
String Laptop::machine_type() const { return String("Laptop"); }

bool Laptop::get_has_touchpad() const { return has_touchpad; }
int Laptop::get_num_usb_ports() const { return num_usb_ports; }

void Laptop::set_has_touchpad(bool value) { has_touchpad = value; }
void Laptop::set_num_usb_ports(int num) { num_usb_ports = num; }

Laptop &Laptop::operator=(const Laptop &other) {
    if (this != &other) {
        PortableMachine::operator=(other);
        has_touchpad = other.has_touchpad;
        num_usb_ports = other.num_usb_ports;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Laptop &laptop) {
    os << static_cast<const PortableMachine &>(laptop);
    os << std::setw(12) << (laptop.has_touchpad ? "yes" : "no") << "\t";
    os << std::setw(13) << laptop.num_usb_ports << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, Laptop &laptop) {
    is >> static_cast<PortableMachine &>(laptop);
    std::cout << "Enter 0 or 1 if laptop has touchpad:\t";
    is >> laptop.has_touchpad;
    std::cout << "Enter number of usb-ports:\t";
    is >> laptop.num_usb_ports;
    return is;
}
