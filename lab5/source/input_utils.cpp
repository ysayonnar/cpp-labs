#include "../../string/string.h"
#include "../include/exeptions/input_exeption.h"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

int input_int(std::istream &input, int min, int max) {
    while (true) {
        try {
            int num;
            std::cout << " (num from " << min << " to " << max << ") ";

            if (input >> num) {
                if (input.peek() != '\n' && input.peek() != EOF) {
                    input.clear();
                    input.ignore(max, '\n');
                    throw InputExeption(1, "invalid input", "invalid");
                }
                input.ignore(max, '\n');
                if (num > max || num < min) {
                    throw InputExeption(2, "value out of bound", "out of bounds");
                }

                return num;
            } else {
                input.clear();
                input.ignore(max, '\n');
                throw InputExeption(1, "invalid", "invalid");
            }
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
            input.clear();
        }
    }
}

int input_float(std::istream &input, float min, float max) {
    while (true) {
        try {
            float num;
            std::cout << " (num from " << min << " to " << max << ") ";

            if (input >> num) {
                if (input.peek() != '\n' && input.peek() != EOF) {
                    input.clear();
                    input.ignore(max, '\n');
                    throw InputExeption(1, "invalid input", "invalid");
                }
                input.ignore(max, '\n');
                if (num > max || num < min) {
                    throw InputExeption(2, "value out of bound", "out of bounds");
                }

                return num;
            } else {
                input.clear();
                input.ignore(INT_MAX, '\n');
                throw InputExeption(1, "invalid input", "invalid");
            }
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
            input.clear();
        }
    }
}

String input_string_eng(std::istream &input) {
    while (true) {
        try {
            int max_len = 80;
            std::cout << " (only English letters A-Z and a-z allowed) ";
            char str[max_len];
            input.getline(str, max_len);
            if (str[0] == '\0') {
                throw InputExeption(1, "invalid input", "value ouf of bounds");
            } else {
                for (int i = 0; str[i] != '\0'; i++) {
                    unsigned char c = str[i];
                    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && c != ' ' && c != '\'' && c != '-') {
                        if (c > 127) {
                            throw InputExeption(4, "only english letters", "invalid");
                        } else {
                            throw InputExeption(1, "invalid input", "value ouf of bounds");
                        }
                    }
                }
                return str;
            }
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
            input.clear();
        }
    }
}
