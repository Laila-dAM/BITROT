#include <stdio.h>
#include <string.h>
#include "login.h"
#include "auth.h"

int login_attempt(const char *username, const char *password) {
    return auth_login(username, password);
}

int logout_user() {
    return auth_logout();
}

int is_user_logged_in() {
    return auth_is_logged_in();
}
