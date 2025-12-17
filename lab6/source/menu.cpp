#include "../include/menu.h"
#include "../include/input_utils.h"
#include <limits>

void Menu::clearStdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
        choice = input_int(0, 5);

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
        std::cout << "0) Back to main menu\n";
        std::cout << "Choice: ";
        choice = input_int(0, 6);

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