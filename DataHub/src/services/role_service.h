#ifndef ROLE_SERVICE_H
#define ROLE_SERVICE_H

#include "../models/role.h"

int service_create_role(const char *name, const char *description);
int service_update_role(int id, const char *name, const char *description);
int service_delete_role(int id);
int service_get_role(int id, Role *role);
int service_list_roles();

#endif
