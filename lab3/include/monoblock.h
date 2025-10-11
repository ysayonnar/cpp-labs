#ifndef MONOBLOCK_H
#define MONOBLOCK_H

#include "personal_computer.h"

class Monoblock : public PersonalComputer {
  protected:
    bool has_built_in_webcam;
    int screen_size;

  public:
    Monoblock(String cpu, String operating_system, int ports_count, String case_form_factor, bool has_built_in_webcam, int screen_size) : PersonalComputer(cpu, operating_system, ports_count, case_form_factor), has_built_in_webcam(has_built_in_webcam), screen_size(screen_size) {}
    Monoblock(const Monoblock &other) : PersonalComputer(other), has_built_in_webcam(other.has_built_in_webcam), screen_size(other.screen_size) {}
    ~Monoblock() = default;

    String machine_type() const override;

    bool get_has_built_in_webcam() const;
    int get_screen_size() const;

    void set_has_built_in_webcam(bool value);
    void set_screen_size(int size);

    Monoblock &operator=(const Monoblock &other);
    friend std::ostream &operator<<(std::ostream &os, const Monoblock &mono);
    friend std::istream &operator>>(std::istream &is, Monoblock &mono);
};

#endif
