#include "../include/vehicle.h"
#include <iostream>

int Vehicle::get_speed() const { return speed; }
int Vehicle::get_price_per_hour() const { return price_per_hour; }

void Vehicle::set_speed(int speed) { this->speed = speed; }
void Vehicle::set_price_per_hour(int price_per_hour) { this->price_per_hour = price_per_hour; }

std::ostream &operator<<(std::ostream &os, const Vehicle &v) {
    os << "Vehicle speed is " << v.speed;
    os << " and price per hour is $" << v.price_per_hour;
    return os;
}

std::istream &operator>>(std::istream &is, Vehicle &v) {
    is >> v.speed;
    is >> v.price_per_hour;
    return is;
}