#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include "../models/user.h"

int has_permission(User *user, const char *permission_name);
int assign_role(User *user, const char *role_name);
int revoke_role(User *user, const char *role_name);

#endif
