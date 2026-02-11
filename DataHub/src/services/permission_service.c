#include "../repositories/permission_repository.h"
#include "permission_service.h"

int service_create_permission(const char *name, const char *description) {
    return repo_create_permission(name, description);
}

int service_update_permission(int id, const char *name, const char *description) {
    return repo_update_permission(id, name, description);
}

int service_delete_permission(int id) {
    return repo_delete_permission(id);
}

int service_get_permission(int id, Permission *permission) {
    return repo_get_permission_by_id(id, permission);
}

int service_list_permissions() {
    return repo_list_permissions();
}
