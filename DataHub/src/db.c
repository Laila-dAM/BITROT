#include <stdio.h>
#include <sqlite3.h>
#include "db.h"

#define DB_FILE "datahub.db"

int db_open(sqlite3 **db) {
    if (sqlite3_open(DB_FILE, db) != SQLITE_OK) {
        printf("Erro ao abrir banco de dados.\n");
        return 0;
    }
    return 1;
}

void db_close(sqlite3 *db) {
    sqlite3_close(db);
}

int db_init(sqlite3 *db) {
    const char *sql =
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE NOT NULL,"
        "password TEXT NOT NULL,"
        "role TEXT NOT NULL"
        ");";

    char *err = NULL;
    if (sqlite3_exec(db, sql, 0, 0, &err) != SQLITE_OK) {
        printf("Erro ao criar tabela users: %s\n", err);
        sqlite3_free(err);
        return 0;
    }

    return 1;
}

int db_add_user(sqlite3 *db,
                const char *username,
                const char *password,
                const char *role) {

    const char *sql =
        "INSERT INTO users (username, password, role) "
        "VALUES (?, ?, ?);";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao preparar INSERT.\n");
        return 0;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, role, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao inserir usuario (talvez ja exista).\n");
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_finalize(stmt);
    return 1;
}
