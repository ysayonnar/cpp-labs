#include "../include/car.h"

int Car::get_passenger_capacity() const { return passenger_capacity; }
String Car::get_model_name() const { return model_name; }

void Car::set_passenger_capacity(int capacity) { this->passenger_capacity = capacity; }
void Car::set_model_name(String model) { this->model_name = model; }

std::ostream &operator<<(std::ostream &os, const Car &c) {
    os << static_cast<const Vehicle &>(c);
    os << ", passenger capacity is " << c.passenger_capacity;
    os << ", model name is " << c.model_name;
    return os;
}

std::istream &operator>>(std::istream &is, Car &c) {
    is >> static_cast<Vehicle &>(c);
    is >> c.passenger_capacity;
    is >> c.model_name;
    return is;
}