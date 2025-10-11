#include "./include/smart_phone.h"
#include <iostream>

int main() {
    SmartPhone myPhone("i15", "iOS", 2400, "IPS", true, "lightning");
    std::cout << myPhone << std::endl;

    std::cout << "Enter params:\t";
    std::cin >> myPhone;
    std::cout << std::endl << myPhone << std::endl;
}