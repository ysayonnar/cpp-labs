#include "../include/laptop.h"

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
    os << "Has touchpad:\t" << (laptop.has_touchpad ? "yes" : "no") << std::endl;
    os << "USB ports:\t" << laptop.num_usb_ports << std::endl;
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
