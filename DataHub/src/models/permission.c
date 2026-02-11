#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "../database/db.h"
#include "permission.h"

int create_permission_db(const char *name, const char *description) {
    char query[512];
    snprintf(query, sizeof(query), 
             "INSERT INTO permissions (name, description) VALUES ('%s', '%s')",
             name, description);
    return db_execute_query(query);
}

int update_permission_db(int id, const char *name, const char *description) {
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE permissions SET name='%s', description='%s' WHERE id=%d",
             name, description, id);
    return db_execute_query(query);
}

int delete_permission_db(int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM permissions WHERE id=%d", id);
    return db_execute_query(query);
}

int get_permission_by_id(int id, Permission *permission) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, name, description FROM permissions WHERE id=%d", id);
    sqlite3 *db = db_get_connection();
    if (!db) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        permission->id = atoi(argv[0]);
        strncpy(permission->name, argv[1], sizeof(permission->name) - 1);
        strncpy(permission->description, argv[2], sizeof(permission->description) - 1);
        return 0;
    }

    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if (err_msg) sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int get_permission_by_name(const char *name, Permission *permission) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, name, description FROM permissions WHERE name='%s'", name);
    sqlite3 *db = db_get_connection();
    if (!db) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        permission->id = atoi(argv[0]);
        strncpy(permission->name, argv[1], sizeof(permission->name) - 1);
        strncpy(permission->description, argv[2], sizeof(permission->description) - 1);
        return 0;
    }

    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if (err_msg) sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int list_all_permissions() {
    const char *query = "SELECT id, name, description FROM permissions";
    sqlite3 *db = db_get_connection();
    if (!db) return 1;

    char *err_msg = NULL;
    int callback(void *NotUsed, int argc, char **argv, char **colName) {
        printf("ID: %s | Name: %s | Description: %s\n", argv[0], argv[1], argv[2]);
        return 0;
    }

    printf("\n=== Permissions List ===\n");
    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if (err_msg) sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}
