#include <string.h>
#include "auth.h"

static UserRole current_role = ROLE_NONE;

int auth_login(const char *username, const char *password)
{
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        current_role = ROLE_ADMIN;
        return 0;
    }

    if (strcmp(username, "user") == 0 && strcmp(password, "user") == 0)
    {
        current_role = ROLE_USER;
        return 0;
    }

    return 1;
}

void auth_logout(void)
{
    current_role = ROLE_NONE;
}

UserRole auth_get_role(void)
{
    return current_role;
}
