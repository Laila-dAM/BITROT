#ifndef PERMISSION_REPOSITORY_H
#define PERMISSION_REPOSITORY_H

#include "../models/permission.h"

int repo_create_permission(const char *name, const char *description);
int repo_update_permission(int id, const char *name, const char *description);
int repo_delete_permission(int id);
int repo_get_permission_by_id(int id, Permission *permission);
int repo_get_permission_by_name(const char *name, Permission *permission);
int repo_list_permissions();

#endif
