#include "string.h"

String::String() : data(nullptr), length(0), capacity(0) {
    allocate(1);
    data[0] = '\0';
}

String::String(const char *str) : data(nullptr), length(0), capacity(0) {
    if (str != nullptr) {
        length = strlen(str);
        allocate(length + 1);
        strcpy(data, str);
    }else {
        allocate(1);
        data[0] = '\0';
    }
}

String::String(const String &other) : data(nullptr), length(other.length), capacity(other.capacity) {
    allocate(capacity);
    strcpy(data, other.data);
}

String::~String() {
    delete[] data;
}


void String::allocate(unsigned int new_size) {
    delete[] data;
    data = new char[new_size];
    capacity = new_size;
}

void String::reallocate(unsigned int new_capacity) {
    char *new_data = new char[new_capacity];
    if (data != nullptr) {
        strcpy(data, new_data);
        delete[] data;
    }

    data = new_data;
    capacity = new_capacity;
}