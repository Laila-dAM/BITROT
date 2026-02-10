#include <stdio.h>
#include "db.h"

sqlite3 *db_open(void) {
    sqlite3 *db = NULL;

    if (sqlite3_open("datahub.db", &db) != SQLITE_OK) {
        printf("Erro ao abrir banco\n");
        return NULL;
    }

    return db;
}

void db_close(sqlite3 *db) {
    if (db) {
        sqlite3_close(db);
    }
}
