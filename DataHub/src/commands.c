#include <stdio.h>
#include <sqlite3.h>
#include "commands.h"

#define DB_FILE "datahub.db"

void cmd_help(void) {
    printf("DataHub CLI\n");
    printf("Commands:\n");
    printf("  help           Show this help\n");
    printf("  init           Initialize system\n");
    printf("  status         Show system status\n");
    printf("  add-user       Add a new user\n");
    printf("  list-users     List all users\n");
}

void cmd_init(void) {
    printf("DataHub inicializado com sucesso.\n");
}

void cmd_status(void) {
    printf("DataHub status: OK\n");
}

void cmd_add_user(const char *username, const char *password, const char *role) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open(DB_FILE, &db) != SQLITE_OK) {
        printf("Erro ao abrir banco.\n");
        return;
    }

    const char *sql =
        "INSERT INTO users (username, password_hash, role_id) "
        "VALUES (?, ?, (SELECT id FROM roles WHERE name = ?));";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao preparar query.\n");
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, role, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao criar usuário.\n");
    } else {
        printf("Usuário criado:\n");
        printf("  Nome: %s\n", username);
        printf("  Role: %s\n", role);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void cmd_list_users(void) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open(DB_FILE, &db) != SQLITE_OK) {
        printf("Erro ao abrir banco.\n");
        return;
    }

    const char *sql =
        "SELECT users.id, users.username, roles.name, users.created_at "
        "FROM users "
        "JOIN roles ON users.role_id = roles.id;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro na query.\n");
        sqlite3_close(db);
        return;
    }

    printf("ID | Username | Role | Created At\n");
    printf("-------------------------------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *username = sqlite3_column_text(stmt, 1);
        const unsigned char *role = sqlite3_column_text(stmt, 2);
        const unsigned char *created = sqlite3_column_text(stmt, 3);

        printf("%d | %s | %s | %s\n",
               id,
               username ? (const char *)username : "-",
               role ? (const char *)role : "-",
               created ? (const char *)created : "-");
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
