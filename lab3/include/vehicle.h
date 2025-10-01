#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
  protected:
    int speed;
    int price_per_hour;

  public:
    Vehicle(int speed, int price_per_hour) : speed(speed), price_per_hour(price_per_hour) {}
    virtual ~Vehicle() = default;

    // геттеры
    int get_speed() const;
    int get_price_per_hour() const;

    // сеттеры
    void set_speed(int speed);
    void set_price_per_hour(int price_per_hour);

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &v);
    friend std::istream &operator>>(std::istream &is, Vehicle &v);
};

#endif
