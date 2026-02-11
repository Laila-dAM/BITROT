#ifndef DB_H
#define DB_H

#include <sqlite3.h>

int db_init();
void db_close();
sqlite3* db_get_connection();
int db_execute_query(const char *query);

#endif
