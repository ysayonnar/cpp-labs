#ifndef CORE_EXEPTION_H
#define CORE_EXEPTION_H

#include <iostream>

class CoreExeption {
  protected:
    int code;
    char message[80];

  public:
    CoreExeption(int code, const char *message) : code(code) { std::strcpy(this->message, message); };
    ~CoreExeption() = default;

    int getCode() { return code; }
    char *getMessage() { return message; }

    friend std::ostream &operator<<(std::ostream &os, const CoreExeption &exp) {
        os << "Code: " << exp.code << ", msg: " << exp.message;
        return os;
    }
};

#endif