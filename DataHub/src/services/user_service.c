#include <stdio.h>
#include <string.h>
#include "../repositories/user_repository.h"
#include "../utils/hash.h"
#include "user_service.h"

int service_create_user(const char *username, const char *password, const char *email) {
    char password_hash[65];
    hash_password(password, password_hash);
    return repo_create_user(username, password_hash, email);
}

int service_update_user(int id, const char *username, const char *password, const char *email) {
    char password_hash[65];
    hash_password(password, password_hash);
    return repo_update_user(id, username, password_hash, email);
}

int service_delete_user(int id) {
    return repo_delete_user(id);
}

int service_get_user(int id, User *user) {
    return repo_get_user_by_id(id, user);
}

int service_list_users() {
    return repo_list_users();
}
