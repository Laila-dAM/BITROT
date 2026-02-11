#include "../repositories/role_repository.h"
#include "role_service.h"

int service_create_role(const char *name, const char *description) {
    return repo_create_role(name, description);
}

int service_update_role(int id, const char *name, const char *description) {
    return repo_update_role(id, name, description);
}

int service_delete_role(int id) {
    return repo_delete_role(id);
}

int service_get_role(int id, Role *role) {
    return repo_get_role_by_id(id, role);
}

int service_list_roles() {
    return repo_list_roles();
}
