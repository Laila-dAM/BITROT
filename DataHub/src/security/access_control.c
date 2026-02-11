#include <stdio.h>
#include <string.h>
#include "../models/user.h"
#include "../models/role.h"
#include "../models/permission.h"
#include "../repositories/role_repository.h"
#include "../repositories/permission_repository.h"
#include "access_control.h"

int has_permission(User *user, const char *permission_name) {
    if (!user) return 0;
    for (int i = 0; i < user->role_count; i++) {
        Role role;
        if (repo_get_role_by_id(user->roles[i], &role)) continue;
        for (int j = 0; j < role.permission_count; j++) {
            Permission perm;
            if (repo_get_permission_by_id(role.permissions[j], &perm)) continue;
            if (strcmp(perm.name, permission_name) == 0) return 1;
        }
    }
    return 0;
}

int assign_role(User *user, const char *role_name) {
    Role role;
    if (repo_get_role_by_name(role_name, &role)) return 1;
    if (user->role_count >= 10) return 1;
    user->roles[user->role_count++] = role.id;
    return 0;
}

int revoke_role(User *user, const char *role_name) {
    Role role;
    if (repo_get_role_by_name(role_name, &role)) return 1;
    int found = -1;
    for (int i = 0; i < user->role_count; i++) {
        if (user->roles[i] == role.id) {
            found = i;
            break;
        }
    }
    if (found == -1) return 1;
    for (int i = found; i < user->role_count - 1; i++) {
        user->roles[i] = user->roles[i + 1];
    }
    user->role_count--;
    return 0;
}
