#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../models/user.h"

int service_create_user(const char *username, const char *password, const char *email);
int service_update_user(int id, const char *username, const char *password, const char *email);
int service_delete_user(int id);
int service_get_user(int id, User *user);
int service_list_users();

#endif
