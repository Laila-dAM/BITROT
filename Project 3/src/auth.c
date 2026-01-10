#include <string.h>
#include "auth.h"

static int authenticated = 0;

int auth_login(const char *username, const char *password)
{
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
    {
        authenticated = 1;
        return 0;
    }
    return 1;
}

void auth_logout(void)
{
    authenticated = 0;
}
