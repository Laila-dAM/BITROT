#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "connection.h"

sqlite3* create_connection() {
    sqlite3 *db = NULL;
    int rc = sqlite3_open("datahub.db", &db);
    if (rc != SQLITE_OK) {
        if (db != NULL) sqlite3_close(db);
        return NULL;
    }
    return db;
}

void close_connection(sqlite3 *db) {
    if (db != NULL) {
        sqlite3_close(db);
    }
}

int test_connection(sqlite3 *db) {
    if (db == NULL) return 0;
    const char *sql = "SELECT 1;";
    char *err_msg = NULL;
    int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if (err_msg != NULL) sqlite3_free(err_msg);
        return 0;
    }
    return 1;
}
