#ifndef PORTABLE_MACHINE_H
#define PORTABLE_MACHINE_H

#include "../../string/string.h"
#include "computing_machine.h"

class PortableMachine : public ComputingMachine {
  protected:
    int battery_capacity = 0;
    String display_type = "";

  public:
    PortableMachine() {};
    PortableMachine(String cpu, String operating_system, int battery_capacity, String display_type) : ComputingMachine(cpu, operating_system), battery_capacity(battery_capacity), display_type(display_type) {}
    PortableMachine(const PortableMachine &other) : ComputingMachine(other), battery_capacity(other.battery_capacity), display_type(other.display_type) {}
    virtual ~PortableMachine() = default;

    void print_header() const override;
    String machine_type() const override;
    void edit() override;

    int get_battery_capacity() const;
    String get_display_type() const;

    void set_battery_capacity(int capacity);
    void set_display_type(String type);

    PortableMachine &operator=(const PortableMachine &other);
    friend std::ostream &operator<<(std::ostream &os, const PortableMachine &machine);
    friend std::istream &operator>>(std::istream &is, PortableMachine &machine);
};

#endif
