#include "../models/role.h"
#include "../database/db.h"
#include "role_repository.h"

int repo_create_role(const char *name, const char *description) {
    return create_role_db(name, description);
}

int repo_update_role(int id, const char *name, const char *description) {
    return update_role_db(id, name, description);
}

int repo_delete_role(int id) {
    return delete_role_db(id);
}

int repo_get_role_by_id(int id, Role *role) {
    return get_role_by_id(id, role);
}

int repo_get_role_by_name(const char *name, Role *role) {
    return get_role_by_name(name, role);
}

int repo_list_roles() {
    return list_all_roles();
}
