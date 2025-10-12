#include "../include/device_menu.h"

void edit_portable(PortableMachine &obj) {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Show\n6. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            obj.set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            obj.set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b;
            std::cin >> b;
            obj.set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s;
            std::cin >> s;
            obj.set_display_type(s);
        } else if (choice == 5) {
            std::cout << obj << std::endl;
        } else if (choice == 6) {
            std::cin >> obj;
        }
    } while (choice != 0);
}

void edit_pc(PersonalComputer &obj) {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set ports count\n4. Set form factor\n5. Show\n6. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            obj.set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            obj.set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Ports: ";
            int p;
            std::cin >> p;
            obj.set_ports_count(p);
        } else if (choice == 4) {
            std::cout << "Form factor: ";
            String s;
            std::cin >> s;
            obj.set_case_form_factor(s);
        } else if (choice == 5) {
            std::cout << obj << std::endl;
        } else if (choice == 6) {
            std::cin >> obj;
        }
    } while (choice != 0);
}

void edit_smartphone(SmartPhone &obj) {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Set camera\n6. Set connector\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            obj.set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            obj.set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b;
            std::cin >> b;
            obj.set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s;
            std::cin >> s;
            obj.set_display_type(s);
        } else if (choice == 5) {
            std::cout << "Has camera (0/1): ";
            int c;
            std::cin >> c;
            obj.set_has_camera(c);
        } else if (choice == 6) {
            std::cout << "Connector: ";
            String s;
            std::cin >> s;
            obj.set_charging_connector_type(s);
        } else if (choice == 7) {
            std::cout << obj << std::endl;
        } else if (choice == 8) {
            std::cin >> obj;
        }
    } while (choice != 0);
}

void edit_laptop(Laptop &obj) {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set battery\n4. Set display\n5. Set touchpad (0/1)\n6. Set USB ports\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            obj.set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            obj.set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Battery: ";
            int b;
            std::cin >> b;
            obj.set_battery_capacity(b);
        } else if (choice == 4) {
            std::cout << "Display: ";
            String s;
            std::cin >> s;
            obj.set_display_type(s);
        } else if (choice == 5) {
            std::cout << "Has touchpad (0/1): ";
            int t;
            std::cin >> t;
            obj.set_has_touchpad(t);
        } else if (choice == 6) {
            std::cout << "USB ports: ";
            int u;
            std::cin >> u;
            obj.set_num_usb_ports(u);
        } else if (choice == 7) {
            std::cout << obj << std::endl;
        } else if (choice == 8) {
            std::cin >> obj;
        }
    } while (choice != 0);
}

void edit_monoblock(Monoblock &obj) {
    int choice;
    do {
        std::cout << "\n1. Set CPU\n2. Set OS\n3. Set ports count\n4. Set form factor\n5. Set webcam (0/1)\n6. Set screen size\n7. Show\n8. Full input (>>)\n0. Back\n> ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "CPU: ";
            String s;
            std::cin >> s;
            obj.set_cpu(s);
        } else if (choice == 2) {
            std::cout << "OS: ";
            String s;
            std::cin >> s;
            obj.set_operating_system(s);
        } else if (choice == 3) {
            std::cout << "Ports: ";
            int p;
            std::cin >> p;
            obj.set_ports_count(p);
        } else if (choice == 4) {
            std::cout << "Form factor: ";
            String s;
            std::cin >> s;
            obj.set_case_form_factor(s);
        } else if (choice == 5) {
            std::cout << "Has webcam (0/1): ";
            int w;
            std::cin >> w;
            obj.set_has_built_in_webcam(w);
        } else if (choice == 6) {
            std::cout << "Screen size: ";
            int sz;
            std::cin >> sz;
            obj.set_screen_size(sz);
        } else if (choice == 7) {
            std::cout << obj << std::endl;
        } else if (choice == 8) {
            std::cin >> obj;
        }
    } while (choice != 0);
}
