#include "string.h"
#include <iostream>

int main() {
    String s1 = String("zalupa");
    String s2 = String("dimki");

    String sum = s1 + s2;
    std::cout << "String: " << sum << std::endl;

    sum += s1;
    std::cout << "String: " << sum << std::endl;

    sum = s1;
    std::cout << "String: " << sum << std::endl;

    std::cout << "i = 2: " << sum[2] << std::endl;
}