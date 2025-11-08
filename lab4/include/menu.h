#ifndef MENU_H
#define MENU_H

#include "laptop.h"
#include "linked_list.hpp"
#include "monoblock.h"
#include "personal_computer.h"
#include "portable_machine.h"
#include "smart_phone.h"
#include <iostream>
#include <string>

class Menu {
  public:
    Menu() = default;
    ~Menu() = default;

    void run();

  private:
    LinkedList<SmartPhone> smartphones;
    LinkedList<Laptop> laptops;
    LinkedList<Monoblock> monoblocks;
    LinkedList<PortableMachine> portables;
    LinkedList<PersonalComputer> pcs;

    template <typename T> void familyMenu(LinkedList<T> &list, const std::string &name);
    template <typename T> void addDevice(LinkedList<T> &list);
    template <typename T> void printDevices(LinkedList<T> &list);
    template <typename T> void editDevice(LinkedList<T> &list);
    template <typename T> void deleteDevice(LinkedList<T> &list);
    template <typename T> void sortDevices(LinkedList<T> &list);
    template <typename T> void searchDevices(LinkedList<T> &list);
    void clearStdin();
};

#endif
