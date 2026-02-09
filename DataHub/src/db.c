#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "db.h"

static sqlite3 *db = NULL;

int db_open(const char *db_path) {
    if (sqlite3_open(db_path, &db) != SQLITE_OK) {
        printf("Database error: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    return 1;
}

void db_close(void) {
    if (db) {
        sqlite3_close(db);
        db = NULL;
    }
}

int db_is_connected(void) {
    return db != NULL;
}

int db_init_schema(const char *schema_file) {
    FILE *file = fopen(schema_file, "r");
    if (!file) {
        printf("Could not open schema file\n");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *sql = malloc(size + 1);
    fread(sql, 1, size, file);
    sql[size] = '\0';

    fclose(file);

    char *err = NULL;
    if (sqlite3_exec(db, sql, 0, 0, &err) != SQLITE_OK) {
        printf("SQL error: %s\n", err);
        sqlite3_free(err);
        free(sql);
        return 0;
    }

    free(sql);
    return 1;
}
