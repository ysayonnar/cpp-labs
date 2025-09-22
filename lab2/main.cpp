#include "string.h"
#include <iostream>

int main() {
    String s("ZALUPA");

    if (s.contains('Z')) {
        std::cout << "True" << std::endl;
    }

    if (!s.contains('Q')) {
        std::cout << "False" << std::endl;
    }

    String ex1("UP");
    String ex2("YAS");

    if (s.contains(ex1)) {
        std::cout << "True" << std::endl;
    }

    if (!s.contains(ex2)) {
        std::cout << "False" << std::endl;
    }
}