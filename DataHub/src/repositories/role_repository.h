#ifndef ROLE_REPOSITORY_H
#define ROLE_REPOSITORY_H

#include "../models/role.h"

int repo_create_role(const char *name, const char *description);
int repo_update_role(int id, const char *name, const char *description);
int repo_delete_role(int id);
int repo_get_role_by_id(int id, Role *role);
int repo_get_role_by_name(const char *name, Role *role);
int repo_list_roles();

#endif
