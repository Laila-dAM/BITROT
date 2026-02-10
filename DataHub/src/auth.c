#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "auth.h"

static int authenticated = 0;
static char current_user[50];

int auth_login(const char *username, const char *password) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int rc;

    rc = sqlite3_open("datahub.db", &db);
    if (rc != SQLITE_OK) {
        printf("Database error.\n");
        return 0;
    }

    const char *sql =
        "SELECT password_hash FROM users WHERE username = ?;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return 0;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *stored = (const char *)sqlite3_column_text(stmt, 0);

        if (strcmp(stored, password) == 0) {
            authenticated = 1;
            strncpy(current_user, username, sizeof(current_user));
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

int auth_is_authenticated() {
    return authenticated;
}

const char* auth_current_user() {
    return current_user;
}
