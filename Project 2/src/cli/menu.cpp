#include "menu.h"
#include <iostream>
#include <vector>

#include "../inventory/item.h"
#include "../inventory/inventory.h"
#include "../db/database.h"

void showMenu(const User& user, Database& db) {
    Inventory inventory(db);

    bool exitMenu = false;
    while (!exitMenu) {
        std::cout << "\n=== Main Menu ===\n";

        if (user.role == Role::Admin) {
            std::cout << "1. Manage Inventory\n";
            std::cout << "2. Reports\n";
            std::cout << "3. Users\n";
            std::cout << "4. Logout\n";
        } 
        else if (user.role == Role::Staff) {
            std::cout << "1. Manage Inventory\n";
            std::cout << "2. Reports\n";
            std::cout << "3. Logout\n";
        } 
        else if (user.role == Role::User) {
            std::cout << "1. View Inventory\n";
            std::cout << "2. Logout\n";
        }

        std::cout << "Select an option: ";
        std::string option;
        std::getline(std::cin, option);

        // 🔹 Logout
        if ((user.role == Role::Admin && option == "4") ||
            (user.role == Role::Staff && option == "3") ||
            (user.role == Role::User && option == "2")) {
            exitMenu = true;
        }

        // 🔹 Inventory (Admin / Staff)
        else if ((user.role == Role::Admin || user.role == Role::Staff) && option == "1") {
            std::vector<Item> items = inventory.getAllItems();

            std::cout << "\n--- Inventory ---\n";
            for (const auto& i : items) {
                std::cout << i.id << ": "
                          << i.name << " x"
                          << i.quantity << " $"
                          << i.price << "\n";
            }
        }

        // 🔹 Inventory (User – somente visualização)
        else if (user.role == Role::User && option == "1") {
            std::vector<Item> items = inventory.getAllItems();

            std::cout << "\n--- Inventory ---\n";
            for (const auto& i : items) {
                std::cout << i.name << " x"
                          << i.quantity << " $"
                          << i.price << "\n";
            }
        }

        else {
            std::cout << "Invalid option\n";
        }
    }
}
