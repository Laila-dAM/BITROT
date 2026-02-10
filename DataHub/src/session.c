#include "session.h"
#include <string.h>

static int active = 0;
static char current_user[50];
static char current_role[50];

void session_start(const char *username, const char *role) {
    strncpy(current_user, username, sizeof(current_user));
    strncpy(current_role, role, sizeof(current_role));
    active = 1;
}

void session_end(void) {
    active = 0;
    current_user[0] = '\0';
    current_role[0] = '\0';
}

int session_is_active(void) {
    return active;
}

const char *session_user(void) {
    return current_user;
}

const char *session_role(void) {
    return current_role;
}
