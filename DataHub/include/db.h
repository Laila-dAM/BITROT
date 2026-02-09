#ifndef DB_H
#define DB_H

#include <sqlite3.h>

int db_open(sqlite3 **db);
void db_close(sqlite3 *db);
int db_init(sqlite3 *db);

int db_add_user(sqlite3 *db,
                const char *username,
                const char *password,
                const char *role);

#endif
