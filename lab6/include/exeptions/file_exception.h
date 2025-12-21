#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H

#include "core_exeption.h"

// File excpetiong cover [51; 100] error codes
// 51 - file not found
// 52 - format error - failbit
// 53 - input/output error - badbit

class FileException : public CoreExeption {
  private:
    char err[20];

  public:
    FileException(int code, const char *message, const char *err) : CoreExeption(code, message) { std::strcpy(this->err, err); }
    ~FileException() = default;

    char *getErr() { return err; }

    friend std::ostream &operator<<(std::ostream &os, const FileException &exp) {
        os << static_cast<const CoreExeption &>(exp);
        os << ", err: " << exp.err;
        return os;
    }
};

#endif