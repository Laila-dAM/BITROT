#include <iostream>
#include <string>
#include "auth/auth.h"
#include "cli/menu.h"

int main() {
    bool running = true;

    while (running) {
        std::cout << "=== Inventory Management System ===\n";
        std::cout << "1. Login\n";
        std::cout << "2. Exit\n";
        std::cout << "Select an option: ";

        std::string option;
        std::getline(std::cin, option);

        if (option == "1") {
            User currentUser;

            if (login(currentUser)) {
                std::cout << "Logged in as: " << currentUser.username << "\n";
                showMenu(currentUser);
            } else {
                std::cout << "Invalid credentials\n";
            }

        } else if (option == "2") {
            running = false;
        } else {
            std::cout << "Invalid option\n";
        }

        std::cout << "\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}
