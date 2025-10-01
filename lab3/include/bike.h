#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

class Bike : public Vehicle {
  private:
    int gear_count;
    bool has_basket;

  public:
    Bike(int speed, int price_per_hour, int gears, bool basket) : Vehicle(speed, price_per_hour), gear_count(gears), has_basket(basket) {}
    ~Bike() = default;

    // геттеры
    int get_gear_count() const;
    bool has_basket() const;

    // сеттеры
    void set_gear_count(int gears);
    void set_basket(bool basket);

    friend std::ostream &operator<<(std::ostream &os, const Bike &c);
    friend std::istream &operator>>(std::istream &is, Bike &c);
};

#endif // BIKE_H
