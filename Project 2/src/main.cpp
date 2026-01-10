#include <iostream>
#include <string>

#include "auth/auth.h"
#include "cli/menu.h"
#include "db/database.h"

int main() {
    Database db("data/inventory.db");

    db.execute(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "password TEXT,"
        "role TEXT);"
    );

    db.execute(
        "CREATE TABLE IF NOT EXISTS items ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "quantity INTEGER,"
        "price REAL,"
        "deleted INTEGER DEFAULT 0);"
    );

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
