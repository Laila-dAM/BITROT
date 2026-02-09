#include <stdio.h>
#include <string.h>
#include <sqlite3.h>
#include "db.h"
#include "users.h"

extern sqlite3 *db;

int user_create(const char *username, const char *password, const char *role) {
    const char *sql =
        "INSERT INTO users (username, password, role) VALUES (?, ?, ?);";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        return 0;

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, role, -1, SQLITE_STATIC);

    int result = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return result;
}

int user_login(const char *username, const char *password) {
    const char *sql =
        "SELECT id FROM users WHERE username = ? AND password = ?;";

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
        return 0;

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    int success = (sqlite3_step(stmt) == SQLITE_ROW);
    sqlite3_finalize(stmt);
    return success;
}

int user_count(void) {
    const char *sql = "SELECT COUNT(*) FROM users;";
    sqlite3_stmt *stmt;

    int count = 0;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            count = sqlite3_column_int(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);
    return count;
}
