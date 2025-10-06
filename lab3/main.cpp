#include "./include/vehicle.h"
#include <iostream>

int main() {
    Vehicle v1(0, 0);
    std::cout << v1 << std::endl;
    std::cout << "Enter speed and price: ";
    std::cin >> v1;
    std::cout << v1 << std::endl;
}