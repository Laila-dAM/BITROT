#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../database/db.h"
#include "role.h"

int create_role_db(const char *name, const char *description) {
    char query[512];
    snprintf(query, sizeof(query), 
             "INSERT INTO roles (name, description) VALUES ('%s', '%s')",
             name, description);
    return db_execute_query(query);
}

int update_role_db(int id, const char *name, const char *description) {
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE roles SET name='%s', description='%s' WHERE id=%d",
             name, description, id);
    return db_execute_query(query);
}

int delete_role_db(int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM roles WHERE id=%d", id);
    return db_execute_query(query);
}

int get_role_by_id(int id, Role *role) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, name, description FROM roles WHERE id=%d", id);
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        role->id = atoi(argv[0]);
        strncpy(role->name, argv[1], 50);
        strncpy(role->description, argv[2], 255);
        return 0;
    }

    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int get_role_by_name(const char *name, Role *role) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, name, description FROM roles WHERE name='%s'", name);
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        role->id = atoi(argv[0]);
        strncpy(role->name, argv[1], 50);
        strncpy(role->description, argv[2], 255);
        return 0;
    }

    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int list_all_roles() {
    const char *query = "SELECT id, name, description FROM roles";
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *NotUsed, int argc, char **argv, char **colName) {
        printf("ID: %s | Name: %s | Description: %s\n", argv[0], argv[1], argv[2]);
        return 0;
    }

    printf("\n=== Roles List ===\n");
    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}
