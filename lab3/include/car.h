#ifndef CAR_H
#define CAR_H

#include "../../string/string.h"
#include "vehicle.h"

class Car : public Vehicle {
  private:
    int passenger_capacity;
    String model_name;

  public:
    Car(int speed, int price_per_hour, int capacity, String model) : Vehicle(speed, price_per_hour), passenger_capacity(capacity), model_name(model) {}
    ~Car() = default;

    // геттеры
    int get_passenger_capacity() const;
    String get_model_name() const;

    // сеттеры
    void set_passenger_capacity(int capacity);
    void set_model_name(String model);

    friend std::ostream &operator<<(std::ostream &os, const Car &c);
    friend std::istream &operator>>(std::istream &is, Car &c);
};

#endif // CAR_H
