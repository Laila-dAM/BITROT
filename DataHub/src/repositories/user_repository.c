#include "../models/user.h"
#include "../database/db.h"
#include "user_repository.h"

int repo_create_user(const char *username, const char *password_hash, const char *email) {
    return create_user_db(username, password_hash, email);
}

int repo_update_user(int id, const char *username, const char *password_hash, const char *email) {
    return update_user_db(id, username, password_hash, email);
}

int repo_delete_user(int id) {
    return delete_user_db(id);
}

int repo_get_user_by_id(int id, User *user) {
    return get_user_by_id(id, user);
}

int repo_get_user_by_username(const char *username, User *user) {
    return get_user_by_username(username, user);
}

int repo_list_users() {
    return list_all_users();
}
