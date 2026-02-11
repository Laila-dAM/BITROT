#include "../models/permission.h"
#include "../database/db.h"
#include "permission_repository.h"

int repo_create_permission(const char *name, const char *description) {
    return create_permission_db(name, description);
}

int repo_update_permission(int id, const char *name, const char *description) {
    return update_permission_db(id, name, description);
}

int repo_delete_permission(int id) {
    return delete_permission_db(id);
}

int repo_get_permission_by_id(int id, Permission *permission) {
    return get_permission_by_id(id, permission);
}

int repo_get_permission_by_name(const char *name, Permission *permission) {
    return get_permission_by_name(name, permission);
}

int repo_list_permissions() {
    return list_all_permissions();
}
