
#ifndef STRING_H
#define STRING_H
#include <cstring>


class String {
private:
    char *data;
    unsigned int length;
    unsigned int capacity;

public:
    String();
    String(const char*);
    String(const String &other);
    ~String();

private:
    void allocate(unsigned int new_size);

    void reallocate(unsigned int new_capacity);
};


#endif