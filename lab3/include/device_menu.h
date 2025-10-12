#ifndef DEVICE_MENU_H
#define DEVICE_MENU_H

#include "laptop.h"
#include "monoblock.h"
#include "personal_computer.h"
#include "portable_machine.h"
#include "smart_phone.h"
#include <iostream>

void edit_portable(PortableMachine &obj);
void edit_pc(PersonalComputer &obj);
void edit_smartphone(SmartPhone &obj);
void edit_laptop(Laptop &obj);
void edit_monoblock(Monoblock &obj);
void clearCin();

#endif
