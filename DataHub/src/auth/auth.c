#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/user.h"
#include "../repositories/user_repository.h"
#include "auth.h"

static User current_user;
static int logged_in = 0;

int auth_login(const char *username, const char *password) {
    User user;
    if (repo_get_user_by_username(username, &user)) return 1;
    if (strcmp(user.password_hash, password) != 0) return 1;
    current_user = user;
    logged_in = 1;
    return 0;
}

int auth_logout() {
    logged_in = 0;
    memset(&current_user, 0, sizeof(User));
    return 0;
}

int auth_is_logged_in() {
    return logged_in;
}

User* auth_get_current_user() {
    if (logged_in) return &current_user;
    return NULL;
}
