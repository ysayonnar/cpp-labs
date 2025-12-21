#include "../include/menu.h"
#include "../include/file.h"
#include "../include/input_utils.h"
#include <cerrno>
#include <cstdint>
#include <limits>
#include <sstream>
#include <sys/stat.h>

void Menu::clearStdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T> void Menu::saveToText(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty. Nothing to save.\n";
        return;
    }
    // ensure files directory exists
    if (mkdir("files", 0755) != 0 && errno != EEXIST) {
        std::cout << "Failed to create files directory\n";
        return;
    }
    std::string type = list.head->value.machine_type().c_str();
    std::string fname = std::string("files/") + type + std::string(".txt");
    try {
        File f(fname);
        f.open(std::ios::out | std::ios::trunc);
        f.file << list.head->value.text_header() << '\n';
        for (ListNode<T> *cur = list.head; cur; cur = cur->next) {
            cur->value.to_text_row(f.file);
            f.file << '\n';
        }
        f.close();
        std::cout << "Saved to " << fname << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error saving file: " << e.what() << "\n";
    }
}

template <typename T> void Menu::loadFromText(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty; cannot infer type to load.\n";
        return;
    }
    std::string type = list.head->value.machine_type().c_str();
    std::string fname = std::string("files/") + type + std::string(".txt");
    try {
        File f(fname);
        f.open(std::ios::in);
        std::string line;
        // read header
        std::getline(f.file, line);
        while (std::getline(f.file, line)) {
            if (line.empty())
                continue;
            T obj;
            obj.from_text_row(line);
            list.push_back(obj);
        }
        f.close();
        std::cout << "Loaded from " << fname << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error loading file: " << e.what() << "\n";
    }
}

template <typename T> void Menu::saveToBinary(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty. Nothing to save.\n";
        return;
    }
    if (mkdir("files", 0755) != 0 && errno != EEXIST) {
        std::cout << "Failed to create files directory\n";
        return;
    }
    std::string type = list.head->value.machine_type().c_str();
    std::string fname = std::string("files/") + type;
    try {
        File f(fname);
        f.open(std::ios::out | std::ios::binary | std::ios::trunc);
        uint32_t count = (uint32_t)list.length;
        f.file.write(reinterpret_cast<const char *>(&count), sizeof(count));
        for (ListNode<T> *cur = list.head; cur; cur = cur->next) {
            cur->value.write_raw(f.file);
        }
        f.close();
        std::cout << "Saved binary to " << fname << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error saving binary file: " << e.what() << "\n";
    }
}

template <typename T> void Menu::loadFromBinary(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty; cannot infer type to load.\n";
        return;
    }
    std::string type = list.head->value.machine_type().c_str();
    std::string fname = std::string("files/") + type;
    try {
        File f(fname);
        f.open(std::ios::in | std::ios::binary);
        uint32_t count = 0;
        f.file.read(reinterpret_cast<char *>(&count), sizeof(count));
        for (uint32_t i = 0; i < count; ++i) {
            T obj;
            obj.read_raw(f.file);
            list.push_back(obj);
        }
        f.close();
        std::cout << "Loaded binary from " << fname << "\n";
    } catch (const std::exception &e) {
        std::cout << "Error loading binary file: " << e.what() << "\n";
    }
}

void Menu::run() {
    int choice = 0;
    do {
        std::cout << "\n=== Main menu: select device family ===\n";
        std::cout << "1) SmartPhone\n";
        std::cout << "2) Laptop\n";
        std::cout << "3) Monoblock\n";
        std::cout << "4) PortableMachine (generic)\n";
        std::cout << "5) PersonalComputer (generic)\n";
        std::cout << "0) Exit\n";
        std::cout << "Choice: ";
        choice = input_int(std::cin, 0, 5);

        switch (choice) {
        case 1:
            familyMenu<SmartPhone>(smartphones, "SmartPhone");
            break;
        case 2:
            familyMenu<Laptop>(laptops, "Laptop");
            break;
        case 3:
            familyMenu<Monoblock>(monoblocks, "Monoblock");
            break;
        case 4:
            familyMenu<PortableMachine>(portables, "PortableMachine");
            break;
        case 5:
            familyMenu<PersonalComputer>(pcs, "PersonalComputer");
            break;
        case 0:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Unknown option.\n";
        }

    } while (choice != 0);
}

template <typename T> void Menu::familyMenu(LinkedList<T> &list, const std::string &name) {
    int choice = 0;
    do {
        std::cout << "\n=== " << name << " menu ===\n";
        std::cout << "1) Add device\n";
        std::cout << "2) Delete device by index\n";
        std::cout << "3) Sort devices (by CPU or OS)\n";
        std::cout << "4) Search devices\n";
        std::cout << "5) Print devices\n";
        std::cout << "6) Edit device by index\n";
        std::cout << "7) Save to text file\n";
        std::cout << "8) Load from text file\n";
        std::cout << "9) Save to binary file\n";
        std::cout << "10) Load from binary file\n";
        std::cout << "0) Back to main menu\n";
        std::cout << "Choice: ";
        choice = input_int(std::cin, 0, 10);

        switch (choice) {
        case 1:
            addDevice<T>(list);
            break;
        case 2:
            deleteDevice<T>(list);
            break;
        case 3:
            sortDevices<T>(list);
            break;
        case 4:
            searchDevices<T>(list);
            break;
        case 5:
            printDevices<T>(list);
            break;
        case 6:
            editDevice<T>(list);
            break;
        case 7:
            saveToText<T>(list);
            break;
        case 8:
            loadFromText<T>(list);
            break;
        case 9:
            saveToBinary<T>(list);
            break;
        case 10:
            loadFromBinary<T>(list);
            break;
        case 0:
            break;
        default:
            std::cout << "Unknown option.\n";
        }

    } while (choice != 0);
}

template <typename T> void Menu::addDevice(LinkedList<T> &list) {
    std::cout << "Enter new device fields via input operator (>>):\n";
    T obj;
    clearStdin();
    if (!(std::cin >> obj)) {
        std::cout << "Failed to read object.\n";
        clearStdin();
        return;
    }
    list.push_back(obj);
    std::cout << "Added.\n";
}

template <typename T> void Menu::printDevices(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty.\n";
        return;
    }
    // print header via first element if possible
    list.head->value.print_header();
    std::cout << std::endl;
    int idx = 0;
    for (ListNode<T> *cur = list.head; cur; cur = cur->next) {
        std::cout << cur->value << std::endl;
        idx++;
    }
}

template <typename T> void Menu::editDevice(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty.\n";
        return;
    }
    int index;
    std::cout << "Enter index to edit: ";
    if (!(std::cin >> index)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        return;
    }
    if (index < 0 || index >= list.length) {
        std::cout << "Index out of range.\n";
        return;
    }
    list[index].edit();
    std::cout << "Edited.\n";
}

template <typename T> void Menu::deleteDevice(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty.\n";
        return;
    }
    int index;
    std::cout << "Enter index to delete: ";
    if (!(std::cin >> index)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        return;
    }
    if (index < 0 || index >= list.length) {
        std::cout << "Index out of range.\n";
        return;
    }
    if (list.erase(index))
        std::cout << "Deleted.\n";
    else
        std::cout << "Delete failed.\n";
}

template <typename T> void Menu::sortDevices(LinkedList<T> &list) {
    if (list.length < 2) {
        std::cout << "Not enough elements to sort.\n";
        return;
    }
    int choice;
    std::cout << "Sort by: 1) CPU  2) OS\nChoice: ";
    if (!(std::cin >> choice)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        return;
    }
    switch (choice) {
    case 1:
        list.sort([&list](int a, int b) { return list[a].get_cpu() < list[b].get_cpu(); });
        break;
    case 2:
        list.sort([&list](int a, int b) { return list[a].get_operating_system() < list[b].get_operating_system(); });
        break;
    default:
        std::cout << "Unknown sort option.\n";
        return;
    }
    std::cout << "Sorted.\n";
}

template <typename T> void Menu::searchDevices(LinkedList<T> &list) {
    if (!list.head) {
        std::cout << "List is empty.\n";
        return;
    }
    int choice;
    std::cout << "Search by: 1) CPU  2) OS\nChoice: ";
    if (!(std::cin >> choice)) {
        clearStdin();
        std::cout << "Invalid input.\n";
        return;
    }
    clearStdin();
    std::string query;
    std::cout << "Enter search string: ";
    std::getline(std::cin, query);
    if (query.empty()) {
        std::cout << "Empty query.\n";
        return;
    }

    switch (choice) {
    case 1: {
        String q(query.c_str());
        ListNode<T> *found = list.find_if([&q](const T &val) { return val.get_cpu() == q; });
        if (found) {
            std::cout << "Found: " << found->value << std::endl;
        } else
            std::cout << "Not found.\n";
        break;
    }
    case 2: {
        String q(query.c_str());
        ListNode<T> *found = list.find_if([&q](const T &val) { return val.get_operating_system() == q; });
        if (found) {
            std::cout << "Found: " << found->value << std::endl;
        } else
            std::cout << "Not found.\n";
        break;
    }
    default:
        std::cout << "Unknown search option.\n";
    }
}