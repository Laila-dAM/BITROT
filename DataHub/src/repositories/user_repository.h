#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include "../models/user.h"

int repo_create_user(const char *username, const char *password_hash, const char *email);
int repo_update_user(int id, const char *username, const char *password_hash, const char *email);
int repo_delete_user(int id);
int repo_get_user_by_id(int id, User *user);
int repo_get_user_by_username(const char *username, User *user);
int repo_list_users();

#endif
