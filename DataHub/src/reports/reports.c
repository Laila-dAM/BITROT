#include <stdio.h>
#include "../repositories/user_repository.h"
#include "../repositories/role_repository.h"
#include "../repositories/permission_repository.h"
#include "../database/db.h"
#include "reports.h"

int generate_users_report() {
    printf("\n=== Users Report ===\n");
    return repo_list_users();
}

int generate_roles_report() {
    printf("\n=== Roles Report ===\n");
    return repo_list_roles();
}

int generate_permissions_report() {
    printf("\n=== Permissions Report ===\n");
    return repo_list_permissions();
}

int generate_access_log_report() {
    const char *query = "SELECT id, user_id, action, timestamp FROM access_logs";
    sqlite3 *db = db_get_connection();
    if (db == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *NotUsed, int argc, char **argv, char **colName) {
        printf("ID: %s | User ID: %s | Action: %s | Timestamp: %s\n", argv[0], argv[1], argv[2], argv[3]);
        return 0;
    }

    printf("\n=== Access Log Report ===\n");
    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}
