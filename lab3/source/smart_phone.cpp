#include "../include/smart_phone.h"
#include <iomanip>

void SmartPhone::print_header() const { std::cout << "Proccesor\tOperating_system\tBattery_capacity\tDisplay_type\tHas_camera\tCharging_adapter_type" << std::endl; }
String SmartPhone::machine_type() const { return String("SmartPhone"); }

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
    is >> phone.has_camera;
    std::cout << "Enter charging connector type:\t";
    is >> phone.charging_connector_type;
    return is;
}