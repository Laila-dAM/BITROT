#include <stdio.h>
#include <string.h>
#include <sqlite3.h>

#include "auth.h"
#include "session.h"

int auth_login(const char *username, const char *password) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open("datahub.db", &db) != SQLITE_OK) {
        printf("Erro ao abrir banco.\n");
        return 0;
    }

    const char *sql =
        "SELECT users.username, roles.name "
        "FROM users "
        "JOIN roles ON users.role_id = roles.id "
        "WHERE users.username = ? AND users.password_hash = ?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro na query.\n");
        sqlite3_close(db);
        return 0;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    int result = 0;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char *user = (const char *)sqlite3_column_text(stmt, 0);
        const char *role = (const char *)sqlite3_column_text(stmt, 1);

        session_start(user, role);
        result = 1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}
