#include "../../string/string.h"
#include "../include/exeptions/input_exeption.h"
#include <cctype>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

int input_int(int min, int max) {
    std::cout << " (num from " << min << " to " << max << ") ";
    while (true) {
        try {
            std::string line;
            if (!std::getline(std::cin, line)) {
                throw InputExeption(1, "invalid input", "eof");
            }

            // trim spaces
            size_t start = line.find_first_not_of(" \t\r\n");
            size_t end = line.find_last_not_of(" \t\r\n");
            if (start == std::string::npos) {
                throw InputExeption(1, "invalid input", "empty");
            }
            std::string token = line.substr(start, end - start + 1);

            // validate that token is an integer with optional +/-, digits only
            size_t i = 0;
            if (token[0] == '+' || token[0] == '-') {
                if (token.size() == 1) {
                    throw InputExeption(1, "invalid integer", "parse error");
                }
                i = 1;
            }
            for (; i < token.size(); ++i) {
                unsigned char c = static_cast<unsigned char>(token[i]);
                if (!std::isdigit(c)) {
                    throw InputExeption(1, "invalid integer", "contains non-digit");
                }
            }

            // convert using strtol and check range
            errno = 0;
            char *endptr = nullptr;
            long val = std::strtol(token.c_str(), &endptr, 10);
            if (endptr == token.c_str() || *endptr != '\0' || errno == ERANGE) {
                throw InputExeption(1, "invalid integer", "parse error");
            }

            if (val < min || val > max) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value must be from %d to %d", min, max);
                throw InputExeption(1, buf, "out of range");
            }

            return static_cast<int>(val);
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}

float input_float(float min, float max) {
    std::cout << " (num from " << min << " to " << max << ") ";
    while (true) {
        try {
            std::string line;
            if (!std::getline(std::cin, line)) {
                throw InputExeption(1, "invalid input", "eof");
            }

            // trim
            size_t start = line.find_first_not_of(" \t\r\n");
            size_t end = line.find_last_not_of(" \t\r\n");
            if (start == std::string::npos) {
                throw InputExeption(1, "invalid input", "empty");
            }
            std::string token = line.substr(start, end - start + 1);

            // parse using strtod and ensure full consumption
            errno = 0;
            char *endptr = nullptr;
            double d = std::strtod(token.c_str(), &endptr);
            if (endptr == token.c_str() || *endptr != '\0' || errno == ERANGE) {
                throw InputExeption(1, "invalid float", "parse error");
            }

            float num = static_cast<float>(d);
            if (num < min || num > max) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value must be from %g to %g", (double)min, (double)max);
                throw InputExeption(1, buf, "out of range");
            }

            return num;
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}

// if min_len and max_len less of equal to 0, they will be ignored
String input_string_eng(int min_len, int max_len) {
    std::cout << " (only English letters A-Z and a-z allowed) ";
    while (true) {
        try {
            std::string tmp;
            if (!std::getline(std::cin, tmp)) {
                throw InputExeption(2, "value can't be empty", "eof");
            }

            // trim spaces
            size_t start = tmp.find_first_not_of(" \t\r\n");
            size_t end = tmp.find_last_not_of(" \t\r\n");
            if (start == std::string::npos) {
                throw InputExeption(2, "value can't be empty", "unacceptable input");
            }
            std::string token = tmp.substr(start, end - start + 1);

            // only English letters A-Z and a-z allowed
            for (size_t i = 0; i < token.size(); ++i) {
                unsigned char c = static_cast<unsigned char>(token[i]);
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                    throw InputExeption(2, "only english letters allowed", "unacceptable input");
                }
            }

            String str(token.c_str());

            if ((min_len > 0 && str.get_length() < min_len) || (max_len > 0 && str.get_length() > max_len)) {
                char buf[80];
                snprintf(buf, sizeof(buf), "value length must be from %d to %d", min_len, max_len);
                throw InputExeption(2, buf, "unacceptable input");
            }

            return str;
        } catch (const InputExeption &e) {
            std::cout << "\terr:" << e << ", insert again\n";
        }
    }
}