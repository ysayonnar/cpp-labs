#ifndef LAPTOP_H
#define LAPTOP_H

#include "portable_machine.h"

class Laptop : public PortableMachine {
  protected:
    bool has_touchpad = false;
    int num_usb_ports = 0;

  public:
    Laptop() {};
    Laptop(String cpu, String operating_system, int battery_capacity, String display_type, bool has_touchpad, int num_usb_ports) : PortableMachine(cpu, operating_system, battery_capacity, display_type), has_touchpad(has_touchpad), num_usb_ports(num_usb_ports) {}
    Laptop(const Laptop &other) : PortableMachine(other), has_touchpad(other.has_touchpad), num_usb_ports(other.num_usb_ports) {}
    ~Laptop() = default;

    void print_header() const override;
    String machine_type() const override;
    void edit() override;

    bool get_has_touchpad() const;
    int get_num_usb_ports() const;

    void set_has_touchpad(bool value);
    void set_num_usb_ports(int num);

    Laptop &operator=(const Laptop &other);
    friend std::ostream &operator<<(std::ostream &os, const Laptop &laptop);
    friend std::istream &operator>>(std::istream &is, Laptop &laptop);
    void to_text_row(std::ostream &os) const override;
    void from_text_row(const std::string &line) override;
    std::string text_header() const override;
    void write_raw(std::ostream &os) const override;
    void read_raw(std::istream &is) override;
};

#endif
