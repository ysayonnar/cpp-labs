#ifndef SERIALIZATION_UTILS_H
#define SERIALIZATION_UTILS_H

#include <cstdint>
#include <cstring>
#include <istream>
#include <ostream>
#include <string>

inline void write_string_raw(std::ostream &os, const char *s) {
    uint32_t len = s ? (uint32_t)strlen(s) : 0;
    os.write(reinterpret_cast<const char *>(&len), sizeof(len));
    if (len)
        os.write(s, len);
}

inline std::string read_string_raw(std::istream &is) {
    uint32_t len = 0;
    is.read(reinterpret_cast<char *>(&len), sizeof(len));
    if (!is || len == 0)
        return std::string();
    std::string s(len, '\0');
    is.read(&s[0], len);
    return s;
}

#endif
