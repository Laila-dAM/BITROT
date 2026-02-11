#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "db.h"

static sqlite3 *db_instance = NULL;

int db_init() {
    int rc = sqlite3_open("datahub.db", &db_instance);
    if (rc != SQLITE_OK) {
        if (db_instance != NULL) sqlite3_close(db_instance);
        db_instance = NULL;
        return 1;
    }
    return 0;
}

void db_close() {
    if (db_instance != NULL) {
        sqlite3_close(db_instance);
        db_instance = NULL;
    }
}

sqlite3* db_get_connection() {
    return db_instance;
}

int db_execute_query(const char *query) {
    if (db_instance == NULL) return 1;
    char *err_msg = NULL;
    int rc = sqlite3_exec(db_instance, query, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if (err_msg != NULL) sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}
