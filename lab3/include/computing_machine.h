#ifndef COMPUTING_MACHINE_H
#define COMPUTING_MACHINE_H

#include "../../string/string.h"
#include <iostream>

class ComputingMachine {
  protected:
    String cpu = "";
    String operating_system = "";

  public:
    ComputingMachine() {};
    ComputingMachine(String cpu, String operating_system) : cpu(cpu), operating_system(operating_system) {}
    ComputingMachine(const ComputingMachine &other) : cpu(other.cpu), operating_system(other.operating_system) {}
    virtual ~ComputingMachine() = default;

    virtual String machine_type() const = 0;
    virtual void print_header() const = 0;

    String get_cpu() const;
    String get_operating_system() const;

    void set_cpu(String c);
    void set_operating_system(String os);

    ComputingMachine &operator=(const ComputingMachine &other);
    friend std::ostream &operator<<(std::ostream &os, const ComputingMachine &machine);
    friend std::istream &operator>>(std::istream &is, ComputingMachine &machine);
};

#endif
