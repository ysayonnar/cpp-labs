#ifndef PERSONAL_COMPUTER_H
#define PERSONAL_COMPUTER_H

#include "../../string/string.h"
#include "computing_machine.h"

class PersonalComputer : public ComputingMachine {
  protected:
    int ports_count = 0;
    String case_form_factor = "";

  public:
    PersonalComputer() {};
    PersonalComputer(String cpu, String operating_system, int ports_count, String case_form_factor) : ComputingMachine(cpu, operating_system), ports_count(ports_count), case_form_factor(case_form_factor) {}
    PersonalComputer(const PersonalComputer &other) : ComputingMachine(other), ports_count(other.ports_count), case_form_factor(other.case_form_factor) {}
    virtual ~PersonalComputer() = default;

    void print_header() const override;
    String machine_type() const override;

    int get_ports_count() const;
    String get_case_form_factor() const;

    void set_ports_count(int count);
    void set_case_form_factor(String form_factor);

    PersonalComputer &operator=(const PersonalComputer &other);
    friend std::ostream &operator<<(std::ostream &os, const PersonalComputer &pc);
    friend std::istream &operator>>(std::istream &is, PersonalComputer &pc);
};

#endif
