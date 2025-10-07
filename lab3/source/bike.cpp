#include "../include/bike.h"

int Bike::get_gear_count() const { return gear_count; }
bool Bike::get_has_basket() const { return has_basket; }

void Bike::set_gear_count(int gears) { this->gear_count = gears; }
void Bike::set_basket(bool basket) { this->has_basket = basket; }

std::ostream &operator<<(std::ostream &os, const Bike &c) {
    os << static_cast<const Vehicle &>(c);
    os << ", gear count: " << c.gear_count;
    os << ", has basket: " << (c.has_basket ? "yes" : "no");
    return os;
}

std::istream &operator>>(std::istream &is, Bike &c) {
    is >> static_cast<Vehicle &>(c);
    is >> c.gear_count;
    is >> c.has_basket;
    return is;
}
