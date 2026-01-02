#ifndef AUTH_H
#define AUTH_H

typedef enum
{
    ROLE_NONE = 0,
    ROLE_USER,
    ROLE_ADMIN
} UserRole;

int auth_login(const char *username, const char *password);
void auth_logout(void);
UserRole auth_get_role(void);

#endif
