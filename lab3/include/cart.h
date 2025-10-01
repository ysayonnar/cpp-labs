#ifndef CART_H
#define CART_H

#include "vehicle.h"

class Cart : public Vehicle {
  private:
    int horse_count;
    int max_weight;

  public:
    Cart(int speed, int price_per_hour, int horse_count, int max_weight) : Vehicle(speed, price_per_hour), horse_count(horse_count), max_weight(max_weight) {}
    ~Cart() = default;

    // геттеры
    int get_horse_count() const;
    int get_max_weight() const;

    // сеттеры
    void set_horse_count(int horse_count);
    void set_max_weight(int max_weight);
};

#endif // CART_H
