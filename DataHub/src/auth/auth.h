#ifndef AUTH_H
#define AUTH_H

#include "../models/user.h"

int auth_login(const char *username, const char *password);
int auth_logout();
int auth_is_logged_in();
User* auth_get_current_user();

#endif
