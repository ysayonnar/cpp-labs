#include "string.h"
#include <iostream>

int main() {
    String s;
    std::cout << "Enter string: ";
    std::cin >> s;

    int min, max;
    std::cout << "Enter min and max values: ";
    std::cin >> min >> max;

    std::cout << "Substring: " << s(min, max) << std::endl;
}