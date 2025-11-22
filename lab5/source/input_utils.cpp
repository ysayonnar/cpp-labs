#include "../../string/string.h"
#include "../include/exeptions/input_exeption.h"
#include <iostream>

int input_int(int min, int max) {
    while (true) {
        try {
            int num;
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InputExeption(1, "invalid input", "parse error");
            }

            if (num < min || num > max) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value must be from %d to %d", min, max);
                throw InputExeption(1, buf, "out of range");
            }

            // consume rest of line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            return num;
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}

float input_float(float min, float max) {
    while (true) {
        try {
            float num;
            if (!(std::cin >> num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw InputExeption(1, "invalid input", "parse error");
            }

            if (num < min || num > max) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value must be from %g to %g", (double)min, (double)max);
                throw InputExeption(1, buf, "out of range");
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}

// if min_len and max_len less of equal to 0, they will be ignored
String input_string_eng(int min_len, int max_len) {
    while (true) {
        try {
            std::string tmp;
            std::getline(std::cin, tmp);
            if (tmp.empty()) {
                // if getline got empty because previous >> left newline, try again
                if (!std::getline(std::cin, tmp) || tmp.empty()) {
                    throw InputExeption(2, "value can't be empty", "unacceptable input");
                }
            }

            // construct String from c_str
            String str(tmp.c_str());

            if ((min_len > 0 && str.get_length() < min_len) || (max_len > 0 && str.get_length() > max_len)) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value length must be from %d to %d", min_len, max_len);
                throw InputExeption(2, buf, "unacceptable input");
            }

            for (int i = 0; i < str.get_length(); i++) {
                if (str[i] > 126 || str[i] < 32) {
                    throw InputExeption(2, "only ascii symbols supported", "unacceptable input");
                }
            }

            return str;
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}