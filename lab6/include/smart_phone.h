#ifndef SMART_PHONE_H
#define SMART_PHONE_H

#include "portable_machine.h"

class SmartPhone : public PortableMachine {
  protected:
    bool has_camera = false;
    String charging_connector_type = "";

  public:
    SmartPhone() {};
    SmartPhone(String cpu, String operating_system, int battery_capacity, String display_type, bool has_camera, String charging_connector_type) : PortableMachine(cpu, operating_system, battery_capacity, display_type), has_camera(has_camera), charging_connector_type(charging_connector_type) {}
    SmartPhone(const SmartPhone &other) : PortableMachine(other), has_camera(other.has_camera), charging_connector_type(other.charging_connector_type) {}
    ~SmartPhone() = default;

    void print_header() const override;
    String machine_type() const override;
    void edit() override;

    bool get_has_camera() const;
    String get_charging_connector_type() const;

    void set_has_camera(bool value);
    void set_charging_connector_type(String type);

    SmartPhone &operator=(const SmartPhone &other);
    friend std::ostream &operator<<(std::ostream &os, const SmartPhone &phone);
    friend std::istream &operator>>(std::istream &is, SmartPhone &phone);
};

#endif
