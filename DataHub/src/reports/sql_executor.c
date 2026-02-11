#include <stdio.h>
#include <sqlite3.h>
#include "../database/db.h"
#include "sql_executor.h"

int execute_sql_query(const char *query) {
    sqlite3 *db = db_get_connection();
    if (db == NULL) return 1;

    char *err_msg = NULL;

    int callback(void *NotUsed, int argc, char **argv, char **colName) {
        for (int i = 0; i < argc; i++) {
            printf("%s ", argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
        return 0;
    }

    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}
