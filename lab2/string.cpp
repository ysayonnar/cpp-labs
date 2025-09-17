#include "string.h"
#include "cstring"
#include <iostream>

String::String() : data(nullptr), length(0), capacity(0) {
    allocate(1);
    data[0] = '\0';
}

String::String(const char *str) : data(nullptr), length(0), capacity(0) {
    if (str != nullptr) {
        length = strlen(str);
        allocate(length + 1);
        strcpy(data, str);
    } else {
        allocate(1);
        data[0] = '\0';
    }
}

String::String(const String &other) : data(nullptr), length(other.length), capacity(other.capacity) {
    if (this != &other) {
        allocate(capacity);
        strcpy(data, other.data);
    }
}

String::~String() { delete[] data; }

String String::operator+(const String &other) {
    String new_string;
    new_string.reallocate(this->length + other.length + 1);
    new_string.data[new_string.capacity] = '\0';
    new_string.length = this->length + other.length;

    if (this->length > 0) {
        std::strcpy(new_string.data, this->data);
    }

    if (other.length > 0) {
        std::strcat(new_string.data, other.data);
    }

    return new_string;
}

String &String::operator+=(const String &other) {
    if (other.length <= 0) {
        return *this;
    }

    unsigned int new_length = this->length + other.length;
    if (new_length + 1 > this->capacity) {
        reallocate(new_length + 1);
    }

    std::strcat(data, other.data);
    this->length = new_length;

    return *this;
}

String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    length = other.length;
    capacity = other.capacity;

    if (other.data != nullptr) {
        data = new char[capacity];
        std::strcpy(data, other.data);
    } else {
        data = nullptr;
    }

    return *this;
}

bool String::operator==(const String &other) { return std::strcmp(this->data, other.data) == 0; }

bool String::operator!=(const String &other) { return std::strcmp(this->data, other.data) != 0; }

bool String::operator<(const String &other) { return std::strcmp(this->data, other.data) < 0; }

bool String::operator>(const String &other) { return std::strcmp(this->data, other.data) > 0; }

bool String::operator<=(const String &other) { return std::strcmp(this->data, other.data) <= 0; }

bool String::operator>=(const String &other) { return std::strcmp(this->data, other.data) >= 0; }

char String::operator[](unsigned int index) {
    if (index < 0 || index >= length) {
        return '\0';
    }

    return data[index];
}

std::ostream &operator<<(std::ostream &os, const String &s) {
    for (int i = 0; i < s.length; i++) {
        os << s.data[i];
    }

    return os;
}

void String::allocate(unsigned int new_capacity) {
    delete[] data;
    data = new char[new_capacity];
    capacity = new_capacity;
}

void String::reallocate(unsigned int new_capacity) {
    char *new_data = new char[new_capacity];
    if (data != nullptr) {
        strcpy(new_data, data);
        delete[] data;
    }

    data = new_data;
    capacity = new_capacity;
}