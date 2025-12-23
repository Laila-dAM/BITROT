#ifndef AUTH_H
#define AUTH_H

#include <string>

enum class Role { Admin, Staff, User, None };

struct User {
    std::string username;
    std::string password;
    Role role;
};

bool login(User& user);

#endif
