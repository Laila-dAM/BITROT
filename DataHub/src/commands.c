#include <stdio.h>
#include <sqlite3.h>
#include "commands.h"

#define DB_FILE "datahub.db"

/* HELP */
void cmd_help(int argc, char *argv[]) {
    printf("DataHub CLI\n");
    printf("Commands:\n");
    printf("  help            Show this help\n");
    printf("  init            Initialize system\n");
    printf("  status          Show system status\n");
    printf("  add-user        Add new user\n");
    printf("  list-users      List all users\n");
}

/* INIT */
void cmd_init(int argc, char *argv[]) {
    printf("DataHub inicializado com sucesso.\n");
}

/* STATUS */
void cmd_status(int argc, char *argv[]) {
    printf("DataHub status: OK\n");
}

/* ADD USER */
void cmd_add_user(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: add-user <username> <password> <role>\n");
        return;
    }

    sqlite3 *db;
    sqlite3_open(DB_FILE, &db);

    char sql[256];
    snprintf(sql, sizeof(sql),
        "INSERT INTO users (username, password, role) VALUES ('%s','%s','%s');",
        argv[2], argv[3], argv[4]);

    sqlite3_exec(db, sql, NULL, NULL, NULL);
    sqlite3_close(db);

    printf("Usuário criado:\n");
    printf("  Nome: %s\n", argv[2]);
    printf("  Role: %s\n", argv[4]);
}

/* LIST USERS */
void cmd_list_users(int argc, char *argv[]) {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    if (sqlite3_open(DB_FILE, &db) != SQLITE_OK) {
        printf("Erro ao abrir banco de dados.\n");
        return;
    }

    const char *sql = "SELECT id, username, role FROM users;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro na query.\n");
        sqlite3_close(db);
        return;
    }

    printf("ID | USERNAME | ROLE\n");
    printf("---------------------\n");

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        printf("%d | %s | %s\n",
            sqlite3_column_int(stmt, 0),
            sqlite3_column_text(stmt, 1),
            sqlite3_column_text(stmt, 2)
        );
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
