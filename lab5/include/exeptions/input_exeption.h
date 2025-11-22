#ifndef INPUT_EXEPTION_H
#define INPUT_EXEPTION_H

#include "core_exeption.h"

// input exeption describes [1; 50] error codes
class InputExeption : public CoreExeption {
  private:
    char err[20];

  public:
    InputExeption(int code, const char *message, const char *err) : CoreExeption(code, message) { std::strcpy(this->err, err); }
    ~InputExeption() = default;

    char *getErr() { return err; }

    friend std::ostream &operator<<(std::ostream &os, const InputExeption &exp) {
        os << static_cast<const CoreExeption &>(exp);
        os << ", err: ", exp.err;
        return os;
    }
};

#endif