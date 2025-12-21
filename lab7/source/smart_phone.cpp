#include "../include/smart_phone.h"
#include "../include/input_utils.h"
#include "../include/serialization_utils.h"
#include <iomanip>
#include <sstream>

void SmartPhone::print_header() const {
    PortableMachine::print_header();
    std::cout << "Has_camera\tCharging_adapter_type\t";
}

String SmartPhone::machine_type() const { return String("SmartPhone"); }

void SmartPhone::edit() {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Set camera\n6. Set connector\n7. Show\n8. Full input (>>)\n0. Back\n> ";
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
            std::cin >> s;
            set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b = input_int(std::cin, 1, 90000);
            set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s = input_string_eng(std::cin);
            set_display_type(s);
        } else if (choice == 5) {
            std::cout << "Has camera (0/1): ";
            int c = input_int(std::cin, 0, 1);
            set_has_camera(c);
        } else if (choice == 6) {
            std::cout << "Connector: ";
            String s = input_string_eng(std::cin);
            set_charging_connector_type(s);
        } else if (choice == 7) {
            std::cout << *this << std::endl;
        } else if (choice == 8) {
            std::cin >> *this;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 0);
}

bool SmartPhone::get_has_camera() const { return has_camera; }
String SmartPhone::get_charging_connector_type() const { return charging_connector_type; }

void SmartPhone::set_has_camera(bool value) { has_camera = value; }
void SmartPhone::set_charging_connector_type(String type) { charging_connector_type = type; }

SmartPhone &SmartPhone::operator=(const SmartPhone &other) {
    if (this != &other) {
        PortableMachine::operator=(other);
        has_camera = other.has_camera;
        charging_connector_type = other.charging_connector_type;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SmartPhone &phone) {
    os << static_cast<const PortableMachine &>(phone);
    os << std::setw(10) << (phone.has_camera ? "yes" : "no") << "\t";
    os << std::setw(20) << (phone.charging_connector_type == "" ? "None" : phone.charging_connector_type) << "\t";
    return os;
}

std::istream &operator>>(std::istream &is, SmartPhone &phone) {
    is >> static_cast<PortableMachine &>(phone);
    std::cout << "Enter 0 or 1 if phone has camera:\t";
    phone.has_camera = input_int(is, 0, 1);
    std::cout << "Enter charging connector type:\t";
    phone.charging_connector_type = input_string_eng(is);
    return is;
}

std::string SmartPhone::text_header() const { return PortableMachine::text_header() + std::string("Has_camera\tCharging_adapter_type\t"); }

void SmartPhone::to_text_row(std::ostream &os) const {
    PortableMachine::to_text_row(os);
    const char *conn = (charging_connector_type == "") ? "" : charging_connector_type.c_str();
    os << (has_camera ? 1 : 0) << '\t' << conn << '\t';
}

void SmartPhone::from_text_row(const std::string &line) {
    PortableMachine::from_text_row(line);
    std::istringstream iss(line);
    std::string token;
    for (int i = 0; i < 5; ++i)
        std::getline(iss, token, '\t');
    if (std::getline(iss, token, '\t'))
        has_camera = (std::stoi(token) != 0);
    if (std::getline(iss, token, '\t'))
        charging_connector_type = String(token.c_str());
}

void SmartPhone::write_raw(std::ostream &os) const {
    PortableMachine::write_raw(os);
    int cam = has_camera ? 1 : 0;
    os.write(reinterpret_cast<const char *>(&cam), sizeof(cam));
    write_string_raw(os, charging_connector_type.c_str());
}

void SmartPhone::read_raw(std::istream &is) {
    PortableMachine::read_raw(is);
    int cam = 0;
    is.read(reinterpret_cast<char *>(&cam), sizeof(cam));
    has_camera = (cam != 0);
    std::string s = read_string_raw(is);
    charging_connector_type = String(s.c_str());
}