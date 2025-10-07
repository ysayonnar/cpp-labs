#include "../include/cart.h"

int Cart::get_horse_count() const { return horse_count; }
int Cart::get_max_weight() const { return max_weight; }

void Cart::set_horse_count(int horse_count) { this->horse_count = horse_count; }

void Cart::set_max_weight(int max_weight) { this->max_weight = max_weight; }

std::ostream &operator<<(std::ostream &os, const Cart &c) {
    os << static_cast<const Vehicle &>(c);
    os << ", horse count is " << c.horse_count;
    os << ", max weight is " << c.max_weight << "kg";
    return os;
}

std::istream &operator>>(std::istream &is, Cart &c) {
    is >> static_cast<Vehicle &>(c);
    is >> c.horse_count;
    is >> c.max_weight;
    return is;
}
