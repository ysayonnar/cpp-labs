#include "string.h"
#include <iostream>

int main() {
    String s;
    std::cout << "Enter string: ";
    std::cin >> s;

    std::cout << "SubString: " << s(0, 3) << std::endl;
}