#include "./include/car.h"
#include <iostream>

int main() {
    Car v1(100, 20, 4, "Toyota");
    std::cout << v1 << std::endl;
    std::cout << "Enter params";
    std::cin >> v1;
    std::cout << v1 << std::endl;
}