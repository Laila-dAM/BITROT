#include "auth.h"
#include <iostream>

bool login(User& user) {
    std::string inputUsername;
    std::string inputPassword;

    std::cout << "Username: ";
    std::getline(std::cin, inputUsername);

    std::cout << "Password: ";
    std::getline(std::cin, inputPassword);

    if (inputUsername == "admin" && inputPassword == "admin") {
        user.username = "admin";
        user.password = "admin";
        user.role = Role::Admin;
        return true;
    }

    if (inputUsername == "staff" && inputPassword == "staff") {
        user.username = "staff";
        user.password = "staff";
        user.role = Role::Staff;
        return true;
    }

    if (inputUsername == "user" && inputPassword == "user") {
        user.username = "user";
        user.password = "user";
        user.role = Role::User;
        return true;
    }

    user.role = Role::None;
    return false;
}
