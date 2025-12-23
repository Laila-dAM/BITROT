#include "menu.h"
#include <iostream>

void showMenu(const User& user) {
    bool exitMenu = false;
    while (!exitMenu) {
        std::cout << "\n=== Main Menu ===\n";

        if (user.role == Role::Admin) {
            std::cout << "1. Manage Inventory\n";
            std::cout << "2. Reports\n";
            std::cout << "3. Users\n";
            std::cout << "4. Logout\n";
        } else if (user.role == Role::Staff) {
            std::cout << "1. Manage Inventory\n";
            std::cout << "2. Reports\n";
            std::cout << "3. Logout\n";
        } else if (user.role == Role::User) {
            std::cout << "1. View Inventory\n";
            std::cout << "2. Logout\n";
        }

        std::cout << "Select an option: ";
        std::string option;
        std::getline(std::cin, option);

        if ((user.role == Role::Admin && option == "4") ||
            (user.role == Role::Staff && option == "3") ||
            (user.role == Role::User && option == "2")) {
            exitMenu = true;
        } else {
            std::cout << "Option selected: " << option << "\n";
        }
    }
}
