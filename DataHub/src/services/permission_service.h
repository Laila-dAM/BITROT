#ifndef PERMISSION_SERVICE_H
#define PERMISSION_SERVICE_H

#include "../models/permission.h"

int service_create_permission(const char *name, const char *description);
int service_update_permission(int id, const char *name, const char *description);
int service_delete_permission(int id);
int service_get_permission(int id, Permission *permission);
int service_list_permissions();

#endif
